<img width="1346" height="772" alt="image" src="https://github.com/user-attachments/assets/48df5fed-53bd-4647-9fc3-069e70dcba8d" />


<h1 align="center">UtiliHand: A Custom Open-Source Robotic Hand</h1>
<p align="center">Project Files:</p>


<p align="center">
  <a href="https://cad.onshape.com/documents/7d4782fc1d2b81b2411dc364/w/61aa74bc50ffa663fe78e913/e/d61dc358418eba5ccd3d28ce?renderMode=0&uiState=6911170d58c8610499119733">Onshape CAD Files</a> •
  <a href="https://docs.google.com/spreadsheets/d/1jZwi7d67DiPdZLEvy5LfeC6HyOPPZ9pO3xaRMX1j6oo/edit?usp=sharing">Bill of Materials</a> •
  <a href="https://blueprint.hackclub.com/projects/599">Blueprint Journal</a>
</p>


I made this to robotic hand to learn more about how robotic hands are designed, built, and how they can be controlled. I also want to explore how accurate and useful they are on the end of the robotic hand I am building. This hand is designed to work using servo motors that pull string to pull the fingers down, and then elastic that pulls the fingers back upright. I learned how to design a custom PCB, encorporate an ESP32, sensors such as force sensors and flex sensors that use I2C and resistors, as well as how to make code to control servo motors.

## Features
- Simple Movement: The joints are simply 3D printed pieces with a metal rod in between that the joints rotate around.
- Cost-Effective: This robot hand with a custom PCB and all the other parts costs around $100, making it pretty cost effective.
- Off-The-Shelf-Components: This robot uses an ESP32, MG996R servo motors, fishing line, and elastic which are all easily sourceable parts.
- Wireless Control: This robot hand is powered by an ESP 32 microcontroller with has WIFI capability
- Mostly 3D Printed: This robot hand is 3D printed and doesn't require any machined parts or gearboxes.

## Design and CAD

The Onshape link can be found at the top of the README.
Each finger joint is 3d printed. A metal rod will go in each joint. The inside of the joint is press fit, and the outer parts are bigger than the rod. So the rod stays press fit, but the outer finger rotates around the rod. This is the full assembly:


<img width="1920" height="1200" alt="image" src="https://github.com/user-attachments/assets/b5817dac-b296-4cfd-be9e-8ed3954415d7" />


This is one finger and joint:


<img width="1920" height="1200" alt="image" src="https://github.com/user-attachments/assets/524e71b8-c973-403a-88c8-0a739b3d0c2f" />


The fishing lines pass through the palm using tunnels. the fishing line ties to the fingertip and then goes through the tunnels and ties to the servo motor. This is an example of those tunnels:


<img width="1920" height="1200" alt="image" src="https://github.com/user-attachments/assets/65863c93-9915-4d41-bbf7-5e7c2b7413c2" />


The forearm holes all the servo motors. They screw onto the forearm using heat-set inserts and M3 hardware. The forearm also includes walls that have holes for the fishing line. This is supposed to tension the fishing line. The forearm also has holes on the sides in which magnets can be inserted. This makes the top of the forearm able to close magnetically making it easier to open and close.


<img width="1920" height="1200" alt="image" src="https://github.com/user-attachments/assets/00ed042b-7aa4-4978-b42d-761a187f71da" />


## PCB and Schematics:

This is the schematic for the custom PCB. The hand is powered from 24v from a bench power supply. An external buck convertor converts it into 6v since that's what the servo motors want. The main controller is an ESP32 Wroom Devkit v1. This has enough pins for all the motors and flex sensors, but an additioal ADS115 ADC Input Board is needed for additional ports for the force sensors. The PCB has JST-XH connectors for all the force and flex sensors. It has 3-pin headers for all the servo motors and screw terminals for the power input and output's. It also includes a port for I2C expansion for the future in case I add a gyroscope, etc. There is also a copper fill throughout the PCB for GND.

<img width="1112" height="787" alt="image" src="https://github.com/user-attachments/assets/19aba3a0-aa85-419b-81ff-73d2023d5121" />

<img width="920" height="892" alt="image" src="https://github.com/user-attachments/assets/e20077b7-118d-4fdf-9902-5e513d7cb19c" />

<img width="975" height="877" alt="image" src="https://github.com/user-attachments/assets/b422c65d-ec55-40eb-8e85-99d86bd327cd" />

## Bill of Materials
These are the components needed. The prices and links can be found here:  <a href="https://docs.google.com/spreadsheets/d/1jZwi7d67DiPdZLEvy5LfeC6HyOPPZ9pO3xaRMX1j6oo/edit?usp=sharing">Bill of Materials Google Sheets</a>

- 1 x PCB
- 3D Printed Parts
- Fishing Line
- 5 x MG996R Servo Motors
- 1 x Glove
- 1 x Elastic Band
- 5 x Flex Sensors
- 5 x FSR402 Force Sensors
- 1 x ESP 32
- 1 x 45mm M4 Bolt
- 1 x 65mm M4 Bolt
- 10 x M3 Heat Set Inserts
- 4 x 6x2 Magnets
- 1 x XH-M404 Buck Convertor
- 5 x JST-XH Pigtail Wires and Connectors
- 5 x 10k Resistors
- 5 x 46k Resistors
- 1 x ADS115 ADC Board
- M3 Hardware
- 9 x JST-XH-2P
- 7 x 3 Pin Headers 2.54mm
- 1 x JST-XH 4P
- 3 x 2 Wire Screw Terminals
- 15 x 1.5mm 20mm Long Metal Rod
