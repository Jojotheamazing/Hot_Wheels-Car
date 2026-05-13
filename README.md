# Hot_Wheels-Car

I am turning a Hot Wheels car into a fully functional RC car controlled by my phone.

So the goal is to get one of my Hot Wheels cars to be functional by adding motors, servos, and everything needed.

## The Plan

- Find the tiniest components I own since the biggest challenge will be space management.
- Design and 3D print a frame that has a steering system and holds all the components in place.
- Solder everything together and test if it goes boom or not.
- Lastly, build a website from which you can control it so there is no need to carry any controller.

## Features

- Front and backward motion through the DRV8833 motor driver.
- 45 degrees steering in each direction for better control and maybe drifting... achieved by using a 1.5 g linear servo.
- The "mind" will be an ESP32-C3 since it has Wi-Fi functions, is small, and powerful. That way control via Wi-Fi becomes possible.
- The website will be pretty basic since I can't get a specific function to work (fetch accelerometer data from phone for steering), so either 2 sliders or a joystick.
- Will include settings like:
  - Servo centre offset and limits
  - Motor limits
  - Expo throttle for smoother acceleration
  - A save button which will save the settings on the ESP32 so there isn't a need to change them every time

## Components

| Component | Purpose | Link |
|---|---|---|
| ESP32-C3 | Main controller with Wi-Fi | [AliExpress](https://www.aliexpress.com/item/1005006109082351.html) |
| DRV8833 Motor Driver | Controls the DC motor | [AliExpress]( https://www.aliexpress.com/item/1005009044264044.html) |
| 1.5 g Linear Servo | Steering system | [AliExpress](https://www.aliexpress.com/item/1005007187617708.html) |
| Coreless DC Motor | The mottion | [AliExpress](https://www.aliexpress.com/item/1005008964639480.html) |
| 601633 LiPo Battery | LiPo battery | [AliExpress](https://www.aliexpress.com/item/1005008218024646.html) |
| TP4056 Charging Module  | Battery charger | [AliExpress](https://www.aliexpress.com/item/1005005982385924.html) |
| SS12D00 3Pin Toggle Switch 1P2T 2 Position  | Power Switch | [AliExpress](https://www.aliexpress.com/item/1005005982385924.html) |
| Mini DC-DC Boost Module | Power for motor | [AliExpress](https://www.aliexpress.com/item/1005007992769446.html) |

---



Feel free to download everything and modify it however you like!

I really want to see your modifications or improvement tips, so contact me anytime!!
