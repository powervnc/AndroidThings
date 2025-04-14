# 🎹 Piano 
## Description
The code found in the Piano file is used to play the notes DO, RE, MI and FA at a certain octave by utilizing 4 buttons. There are 3 octaves, one "LOW", one "MEDIUM" and one "HEIGH" that the user can opt to use at any moment.
At the start of the program, the user uses the one in the middle, but using a switch on the y-axis, the user can move through them:
- when we move the joystick "UP", we shift to a higher octave.
- when we move the joystick "DOWN". we shift to a lower octave.

The joystick mechanism is meant to compensate for the limitations caused by the fixed number of buttons, allowing the user greater freedom.

## Schematics
![Image](https://github.com/user-attachments/assets/8b81c665-a6cf-4c95-9702-f469b43d6e02)
![Image](https://github.com/user-attachments/assets/e1c2b4f6-abce-4c9a-af22-11d9822a5f2d)


## Pre-requisites
- Uno R3 board https://docs.arduino.cc/hardware/uno-rev3/
- full-size breadboard
- 4 push-down buttons https://theorycircuit.com/arduino-projects/simple-arduino-push-button-switch-tutorial/
- active buzzer https://microcontrollerslab.com/buzzer-module-interfacing-arduino-sound-code/
- Joystick Module https://components101.com/modules/joystick-module
- wires(5 male-to-female, 12 male-to-male) https://www.yamanelectronics.com/types-of-jumper-wires/



## 🛠️ Set-up and Build
###  Components and Wiring

- **Buttons (x4):**
  - Connect one side of each button to **digital pins 4, 5, 6, and 7** (one pin per button).
  - Connect the other side of each button to the **GND rail** on the breadboard.

- **Buzzer:**
  - Connect the **positive (+) pin** to **digital pin 3**.
  - Connect the **negative (–) pin** to the **GND rail** on the breadboard.

- **Joystick:**
  - **SW (Button press)** → **Digital pin 12**
  - **VRx (Horizontal axis)** → **Analog pin A1**
  - **VRy (Vertical axis)** → **Analog pin A0**
  - **VCC (Power)** → **+5V rail** on the breadboard
  - **GND** → **GND rail** on the breadboard

> ✅ The breadboard's power rails are connected to the Arduino's **5V** and **GND** pins to supply power to all components properly.
### We do not use any additional libraries. 

## ▶️ Running
Once the program is uploaded, the system will continuously monitor the joystick's position to determine the selected octave. Each time the joystick is moved, the system checks which octave should be active. The user will be able to perceive the change in pitch based on the octave setting when pressing one of the four note buttons.

### 1. 🎶 Play the Notes
- Press any of the 4 buttons to play the corresponding notes: **DO**, **RE**, **MI**, and **FA**.
- The joystick allows you to change the octave, offering a dynamic playing experience. By moving the joystick **UP** or **DOWN**, you can switch between the **LOW**, **MEDIUM**, and **HIGH** octaves.

### 2. 🔄 Octave Shifting
- The joystick is used to navigate between octaves:
  - Moving the joystick **UP** switches to a **higher octave**.
  - Moving the joystick **DOWN** switches to a **lower octave**.

As you move the joystick, the system instantly adjusts the octave, and the corresponding note pitch will reflect this shift.



