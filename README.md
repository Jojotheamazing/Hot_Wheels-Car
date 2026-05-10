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

---

Feel free to download everything and modify it however you like!

I really want to see your modifications or improvement tips, so contact me anytime!!
