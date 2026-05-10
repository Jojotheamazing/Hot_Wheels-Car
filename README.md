# Hot_Wheels-Car
I am turning a hot wheel car into a fully functional rc car controlled by my phone.

So the goal is to get one of my Hot Wheels to be functional by adding motors servos and everything needed.

The plan:
Find the tiniest components I own since the biggest challenge will be space managment.
Design and 3d print a frame that has a steering system and hold all the components in place.
Solder everything together and test if it goes boom or not.
Lastly build a website from which you can control it so there is not need to carry any controller.

Features:
Front and backwards motion through the drv8833 motor driver.
45 degrees steering each direction for better control and maybe drifting... achived by using a 1.5 gr linear servo.
The "mind" will be an esp32 c3 since it has wifi functions, is small and powerful. That way control via wifi becomes possible.
The website will be pretty basic since I cant get a specific function to work(fetch accelarometer data from phone for steering) so either 2 sliders or a joystick. 
Will include: settings like servo centre offset and limits, motor limits and expo throttle for smoother accelaration and a save button which will save the setting on the esp32 so there isnt a need to change them every time.


Feel free to download everything and modify it however you like!
I really want to see your modifications or improvement tips so contact me anytime!!
