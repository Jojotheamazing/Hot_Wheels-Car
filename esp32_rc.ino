#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>

// ======================
// WIFI
// ======================

const char* ssid = "ESP32_RC";
const char* password = "12345678";

// ======================
// WEB
// ======================

WebServer server(80);
WebSocketsServer ws(81);

// ======================
// PINS
// ======================

const int servoPin = 6;
const int IN1      = 3;
const int IN2      = 4;

// ======================
// SERVO (LEDC direct)
// 50Hz, 14-bit resolution
// 20000us period = 16383 ticks
// ======================

const int SERVO_FREQ = 50;
const int SERVO_BITS = 14;

const int SERVO_MIN    = 500;   // us
const int SERVO_CENTER = 1300;  // us — adjust if needed
const int SERVO_MAX    = 2100;  // us

// ======================
// MOTOR (LEDC)
// 1kHz, 8-bit resolution
// ======================

const int MOTOR_FREQ = 1000;
const int MOTOR_BITS = 8;

// ======================
// CONTROL
// ======================

int servoInput = 0;
int motorInput = 0;

unsigned long lastPacket = 0;

// ======================
// HTML
// ======================

String page = R"rawliteral(

<!DOCTYPE html>
<html>

<head>
<meta name="viewport" content="width=device-width, initial-scale=1">

<style>
body{
  font-family:Arial;
  text-align:center;
  background:#f0f0f0;
}

.box{
  background:white;
  margin:15px;
  padding:15px;
  border-radius:15px;
}

input{
  width:90%;
}
</style>

</head>

<body>

<h2>ESP32 RC</h2>

<div class="box">
<h3>Steering</h3>
<input id="servo" type="range" min="-100" max="100" value="0">
</div>

<div class="box">
<h3>Throttle</h3>
<input id="motor" type="range" min="-100" max="100" value="0">
</div>

<script>

var ws = new WebSocket("ws://192.168.4.1:81/");
var ready = false;

ws.onopen = function(){ ready = true; };
ws.onclose = function(){ ready = false; };

var servoSlider = document.getElementById("servo");
var motorSlider = document.getElementById("motor");

setInterval(function(){
  if(ready){
    ws.send("C," + servoSlider.value + "," + motorSlider.value);
  }
}, 50);

</script>

</body>
</html>

)rawliteral";

// ======================
// HTTP
// ======================

void handleRoot(){
  server.send(200, "text/html", page);
}

// ======================
// WEBSOCKET
// ======================

void onWS(
  uint8_t num,
  WStype_t type,
  uint8_t * payload,
  size_t length
){

  if(type == WStype_TEXT){

    String msg = String((char*)payload);

    if(msg.startsWith("C,")){

      sscanf(
        msg.c_str(),
        "C,%d,%d",
        &servoInput,
        &motorInput
      );

      lastPacket = millis();
    }
  }
}

// ======================
// SERVO WRITE
// us = microseconds (500-2100)
// ======================

void servoWrite(int us){
  us = constrain(us, SERVO_MIN, SERVO_MAX);
  int duty = (int)(us * 16383.0 / 20000.0);
  ledcWrite(servoPin, duty);
}

// ======================
// MOTOR WRITE
// throttle = -100 to 100
// ======================

void motorWrite(int throttle){

  if(abs(throttle) < 15){
    ledcWrite(IN1, 0);
    ledcWrite(IN2, 0);
    return;
  }

  int pwm = map(abs(throttle), 15, 100, 60, 255);
  pwm = constrain(pwm, 0, 255);

  if(throttle > 0){
    ledcWrite(IN1, pwm);
    ledcWrite(IN2, 0);
  }
  else{
    ledcWrite(IN1, 0);
    ledcWrite(IN2, pwm);
  }
}

// ======================
// SETUP
// ======================

void setup(){

  Serial.begin(115200);

  // ===== SERVO =====

  ledcAttach(servoPin, SERVO_FREQ, SERVO_BITS);
  servoWrite(SERVO_CENTER);

  delay(500);

  // ===== MOTOR =====

  ledcAttach(IN1, MOTOR_FREQ, MOTOR_BITS);
  ledcAttach(IN2, MOTOR_FREQ, MOTOR_BITS);
  ledcWrite(IN1, 0);
  ledcWrite(IN2, 0);

  // ===== WIFI =====

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  delay(500);

  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  // ===== SERVER =====

  server.on("/", handleRoot);
  server.begin();

  ws.begin();
  ws.onEvent(onWS);

  Serial.println("READY");
}

// ======================
// LOOP
// ======================

void loop(){

  server.handleClient();
  ws.loop();

  // ======================
  // SERVO
  // ======================

  int us = map(
    servoInput,
    -100,
    100,
    SERVO_MIN,
    SERVO_MAX
  );

  servoWrite(us);

  // ======================
  // MOTOR
  // ======================

  motorWrite(motorInput);

  // ======================
  // FAILSAFE
  // ======================

  if(millis() - lastPacket > 1000){

    servoInput = 0;
    motorInput = 0;

    servoWrite(SERVO_CENTER);

    ledcWrite(IN1, 0);
    ledcWrite(IN2, 0);
  }

  delay(2);
}
