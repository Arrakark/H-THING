# H-THING

An H-Bridge circuit for controlling a single robot motor.

## PCB Description

![Schematic](https://raw.githubusercontent.com/Arrakark/H-THING/master/schematic.png)

![PCB](https://raw.githubusercontent.com/Arrakark/H-THING/master/pcb.png)

![3d view](https://raw.githubusercontent.com/Arrakark/H-THING/master/3d.png)

### Specs

* 5V - 17V motor voltage range
* To be used with <1000Hz switching freqnuency (500Hz is preferred)
* Supports 3.3v and 5.0v logic level inputs
* Capable of driving up to 3A
* Requires only one PWM pin for speed, one digial I/O for direction
* Can be used as a half-bridge if direction pin is disconnected
* Has space for a current-sensing resistor (R6)
* **Cannot be used to coast the motor**

This project was created using KiCad 5 RC2. Use it to open and edit this design.

### BOM

| "Id" | "Designator"      | "Package"                                        | "Quantity" | "Designation"           | "Supplier and ref" |  |  | 
|------|-------------------|--------------------------------------------------|------------|-------------------------|--------------------|--|--| 
| 1    | "MH3,MH2,MH4,MH1" | "MountingHole_3.2mm_M3"                          | 4          | "MountingHole_3.2mm_M3" |                    |  |  | 
| 2    | "C1,C3"           | "C_Disc_D5.0mm_W2.5mm_P5.00mm"                   | 2          | "100nF"                 |                    |  |  | 
| 3    | "C2"              | "CP_Radial_D10.0mm_P5.00mm"                      | 1          | "470uF"                 |                    |  |  | 
| 4    | "J1"              | "TerminalBlock_bornier-2_P5.08mm"                | 1          | "MOTOR_CON"             |                    |  |  | 
| 5    | "J2"              | "TerminalBlock_bornier-2_P5.08mm"                | 1          | "PWR_PASSTHRU"          |                    |  |  | 
| 6    | "J3"              | "TerminalBlock_bornier-2_P5.08mm"                | 1          | "MAIN_PWR"              |                    |  |  | 
| 7    | "Q1,Q6"           | "TO-92_Inline_Narrow_Oval"                       | 2          | "2N3904"                |                    |  |  | 
| 8    | "R1,R2,R4,R5"     | "R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" | 4          | "1k00"                  |                    |  |  | 
| 9    | "J4"              | "Socket_Strip_Straight_1x03_Pitch2.54mm"         | 1          | "SIG_CON"               |                    |  |  | 
| 10   | "Q2,Q4"           | "TO-220-3_Vertical"                              | 2          | "IRF5305"               |                    |  |  | 
| 11   | "Q3,Q5"           | "TO-220-3_Vertical"                              | 2          | "HUF75321"              |                    |  |  | 
| 12   | "R6"              | "R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" | 1          | "0R20"                  |                    |  |  | 
| 13   | "G***"            | "rover"                                          | 1          | "LOGO"                  |                    |  |  | 


## Installing

Install the H-THING using standoffs on the robot. Apply motor power (10-17V) to the screw terminals on the right hand side. **Make sure the polarity is correct!** The other screw terminal is for power pass-trough. Use the passthrough to chain more H-THINGs together. Finally, connect the motor to the last screw terminal (the one with the motor label).

Connect the H-THING to a microcontroller by connecting one of the outermost pins to a PWM pin, and the other to a digital I/O (non PWM).

## Signal Control

Use the library included with this repo to control the speed and direction of the motor. 

Use the following code to create a H-THING object:
```
#define SPEED_PIN 9 
#define DIR_PIN 3 
left_motor hthing(SPEED_PIN, DIR_PIN);
```
To control the motor:
```
left_motor.run(0,200); //runs the left motor backwards at 200/255% speed
left_motor.run(1,255); //runs the left motor forwards at full speed
left_motor.stop(); //stops the motor
left_motor.run(-255); //runs the motor backwards
left_motor.run(120); //runs the motor forwards
```

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/Arrakark/H-THING/blob/master/LICENSE) file for details

## Acknowledgments

* Special thanks to the V2FC robot team!
