# Design-of-4-Way-Traffic-Light-Controller-Based-on-Finite-State-Machine-FSM-Using-Verilog
The objective of this project is to develop a traffic light control system using Verilog and Proteus. The algorithm for doing this is based on Finite State Machine
(FSM) .

Demonstration Video <a href="https://youtu.be/iB-ycT9aWPk">link</a>

## Contents

## Softwares Used
- Quartus
- Proteus
- Ardunio IDE
## Description
***

There are four roads: East, North, West, South. The green light will go on
circularly in the counter-clockwise direction. The green light will remain on for 20
seconds. In this period all other roads will be red. Then, the yellow light will light
up and the next road to be green will be in a red-yellow state to caution the
drivers. The system will be in this state for 4 seconds. There are also sensors in
each road which will determine if there is a jam, emergency in the road or if the
road is empty.

## Extra Features

There are three extra features in this system:
1. If emergency vehicles come into a road, then turn on the green light of that road immediately.
2. If there is a jam on a road, then turn on the green light of that road immediately.
3. If a road is empty while in the green state, it will immediately turn to the yellow state.

## State Diagram

***
There are eight states in the state diagram which are green and yellow states for each road. In the green state of a road, only that road will be green, others will be red. The system will remain for 20 seconds in this state. In the yellow state of a road, the corresponding road will be yellow, the next road to be green will be red-yellow and others will be red. The system will remain for 4 seconds in this state. The states of the system will rotate as shown in the figure.
## Description of States
<p align="center">
  <img src="https://user-images.githubusercontent.com/66994793/137627659-c72f2075-0376-4411-8f9b-b8e3c778cb9f.png" title="Different states">
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/66994793/137627661-0833e332-0482-42ba-9145-53792be68e80.png" title="Traffic Lights">
</p>


## Flowchart
***
In the flowchart, we can see how the logical part of the program will work. At first, the program will check if there is an emergency on any of the roads. If there is, then the system will switch to the green state of that road immediately. If there is no emergency on any road, then it will check if there is a jam on any road and act similarly as an emergency condition. After this, the program will check if the present state is green or yellow. If it is green, then it will check if the road is empty or 20 seconds have passed or not. If yes, then it will move to the yellow of the corresponding road and continue the loop, otherwise, it will remain in the green state. If the present state is yellow, then the program will check if 4 seconds have passed or not. If yes, then it will move to the green of the next road and continue the loop, otherwise, it will remain in a yellow state. 
## Emergency condition

<p align="center">
  <img src="https://user-images.githubusercontent.com/66994793/137627678-199c7e93-2b8b-470f-96af-0bb5eb81e0d0.png" title="Emergency">
</p>


The emergency condition is implemented by using a 4-bit variable named Emergency. If Emergency[3] is 1 then it means that the east road has an emergency condition and the system goes to east_green state whose binary value is 000. Similarly, emergency conditions for other roads are implemented.

## Jam Condition
<p align="center">
  <img src="https://user-images.githubusercontent.com/66994793/137627686-1c6a4944-656d-4319-b3e7-93accee70a3c.png" title="Jam">
</p>

Similarly, the jam condition is implemented using a 4-bit variable Jam. It’s operation is like that of the emergency condition.

## Verilog Code
## Timing Diagram
## Hardware Simulation
We have used an Arduino Mega board to carry out our hardware simulation in Proteus.
### Schematics
### Arduino Code explanation using snippets

## Team
- Ramit Dutta (github - https://github.com/RamitDutta)
- Shafin Bin Hamid (github - https://github.com/shafinbinhamid)
-  Md. Asif Iqbal
