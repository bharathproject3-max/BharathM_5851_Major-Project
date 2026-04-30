# Climate Control Module - UNLOX Minor Project

A production-grade embedded IoT system built to monitor ambient temperature and dynamically scale a DC motor's speed using Pulse Width Modulation (PWM). This project was developed as a minor project submission for Unlox Academy[cite: 1].

## 🎯 Objective
To build a highly responsive, non-blocking Climate Control System that maps temperature readings to motor velocity, ensuring optimal thermal management without halting the microcontroller's execution loop[cite: 1].

## ⚙️ Functional Requirements Achieved
* **Continuous Monitoring:** Reads temperature seamlessly without blocking execution[cite: 1].
* **Dynamic Control:** Motor is OFF below 27°C, scales linearly, and hits max speed (PWM = 255) at 40°C[cite: 1].
* **Data Logging:** Prints telemetry data every 500 ms in the format: `Temp: [Value]C, PWM: [Value]`[cite: 1].

## 🛠️ Hardware & Circuitry
* **Microcontroller:** Arduino Uno / ESP32
* **Temperature Sensor:** LM35 (or similar analog sensor)
* **Actuator:** 5V DC Motor with an NPN Transistor (e.g., TIP120)
* **Protection:** Flyback diode and base resistor included for circuit stability

> **Note:** The complete wiring schematic can be found in the `Circuit_Diagram.pdf` file included in this repository.

## 📂 Repository Structure
This repository adheres to the UNLOX submission guidelines[cite: 1].
```text
BharathM_5851_ClimateControlProject/
│
├── ClimateControl.ino       # Main firmware source code
├── Circuit_Diagram.pdf      # High-resolution circuit schematic
└── README.md                # Project documentation
