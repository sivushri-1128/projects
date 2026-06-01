Smart Blind Stick

An Arduino-based assistive device designed to help visually impaired individuals detect obstacles in three directions (Left, Front, Right) using ultrasonic sensors and receive alerts through a buzzer.

Project Overview

The Smart Blind Stick enhances mobility and safety by detecting nearby obstacles and providing direction-based audio feedback. It uses multiple ultrasonic sensors to scan the surroundings and alerts the user with different buzzer patterns.

Features

3-Directional Obstacle Detection (Left, Front, Right)
Different Buzzer Alerts for Each Direction

  * Front → Very Fast Beep (High Danger)
  * Left → Medium Speed Beep
  * Right → Slow Beep
* Real-time distance measurement
* Simple and cost-effective solution


Working Principle

* Ultrasonic sensors emit sound waves.
* When the waves hit an object, they reflect back.
* The time taken for the echo to return is used to calculate distance.
* Based on the detected direction and distance:

  * **Front obstacle → Immediate fast alert**
  * **Left obstacle → Medium alert**
  * **Right obstacle → Slow alert**

Priority is given as:

Front > Left > Right

Components Used

* Arduino Uno - 2
* 3 × Ultrasonic Sensors (HC-SR04)
* Buzzer
* Jumper Wires
* Power Supply

Circuit Connections

Ultrasonic Sensors

Direction Trig Pin Echo Pin 
Left      D2       D3       
Front     D4       D5       
Right     D6       D7       

Other Components

Component Pin
Buzzer    D8
VCC       5V
GND       GND

Output / Demo

![Hardware image](smart blind stick.jpg)

Applications

* Assistive technology for visually impaired individuals
* Obstacle detection systems
* Robotics and automation projects

Future Improvements

* Voice output (Left/Right/Front alerts)
* Vibration motor instead of buzzer
* IoT integration (alerts to mobile)
* AI-based object detection
