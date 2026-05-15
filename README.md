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
| 1.2mm Nails | For steering wheels | Anywhere |
---
You can see and edit the 3d model in onShape: https://cad.onshape.com/documents/f10e87d5d1a2dad3236470ab/w/f1481a050fec03bc3c35e125/e/4facaef65102b49a36f9e8eb?renderMode=0&uiState=6a06d694dea5e7e2bb82ecd9

## Wiring

Here is an image showing all the connections but here are some notes too:
- On the boost converter you need to unsolder the b pad and only leave A soldered to set it to 9 volts
- All the Black wires are ground and it doesnt matter in which ground you connect it.
- The bright red wire is the battery power while the dark red is 9 volts so becareful not to mix it up and burn anything.
- The in1 and in2 doesnt matter if you reverse it same with out1 and out2 you might just need to reverse the diraction in the code.
  
<img width="1672" height="941" alt="Schematic" src="https://github.com/user-attachments/assets/78129510-1490-4b84-ada9-800b9cbb02ff" />


I should also credit an amazing YouTuber which I got inspiration for this project idea: @MaxImagination
Go check his other projects: https://www.youtube.com/@MaxImagination

Feel free to download everything and modify it however you like!

I really want to see your modifications or improvement tips, so contact me anytime!!
