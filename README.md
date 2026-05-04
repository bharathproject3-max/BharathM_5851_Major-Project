# Smart Home Ecosystem: Adaptive Climate, Illumination, and Security Automation

![Platform](https://img.shields.io/badge/Platform-ESP32%20%7C%20NodeMCU-blue)
![Language](https://img.shields.io/badge/Language-C++%20(Arduino)-orange)
![Simulation](https://img.shields.io/badge/Simulation-Wokwi-purple)

## 📌 Project Overview
This project is an industry-grade IoT ecosystem designed to simulate the architectural principles of modern residential automation. It integrates autonomous environmental sensing, edge-based decision-making, and real-time actuation to create a responsive "Living Space." 

The core engineering achievement of this project is the **Asynchronous, Non-Blocking Logic Engine**. By completely abandoning traditional `delay()` functions and utilizing a `millis()`-based Finite State Machine (FSM), the central microcontroller achieves true parallel processing—monitoring climate, illumination, and security interrupts simultaneously without any system latency

## ✨ Core Features & Modules
1. **Adaptive Climate Control (HVAC):** Autonomous thermal management utilizing a DHT22 sensor. Triggers a localized cooling response (LED/Fan) when ambient temperature exceeds **30.0°C**, featuring a hysteresis shutdown loop.
2. **Intelligent Ambient Illumination:** Energy conservation module utilizing a Photoresistor (LDR) on a 12-bit ADC. Automatically activates indoor lighting during low-light conditions (< 2000 ADC) and deactivates during peak daylight.
3. **Proactive Intrusion Detection:** Primary perimeter defense. Bypasses standard comfort protocols to trigger aggressive auditory alarms upon detecting unauthorized entry or interrupts when the system is "Armed."
4. **Automated Access & Entry:** Smart digital door simulation utilizing an SG90 Servo motor. Features a non-blocking 5-second time-locked auto-close sequence to ensure structural integrity.
5. **Global State Governance:** Hardware interrupt (Slide Switch) to toggle the entire ecosystem between **Normal Mode** (Comfort) and **Security Mode** (High-sensitivity monitoring).

## 🛠️ Hardware & Technical Stack
### Microcontroller Blueprint
* **Physical Architecture:** NodeMCU (ESP8266)
* **Simulation Architecture:** ESP32 (Upgraded for stable Wokwi digital twin validation & advanced ADC).

### Sensor & Actuator Array
* **Thermal:** DHT22 (1-Wire Digital)
* **Luminosity:** Photoresistor Module (LDR)
* **Access/Interrupts:** Pushbutton (Doorbell), Slide Switch (State Toggle)
* **Actuators:** SG90 Micro Servo, Piezo Buzzer, 5mm Discrete LEDs (Blue/Yellow)

## 💻 Software Architecture
* **Environment:** Arduino IDE (C++)
* **Timing Logic:** Hardware-timer polling via `millis()` (Zero `delay()` functions).
* **State Management:** Finite State Machine (FSM) utilizing boolean flags (`isDoorOpen`, `isArmed`).
* **Libraries:** `DHT sensor library` (Adafruit), `ESP32Servo`.

## 🚀 Running the Digital Twin (Wokwi)
The physical schematic was successfully validated using the Wokwi Digital Twin environment. 
1. Open the [Wokwi Simulator](https://wokwi.com/).
2. Load the `main.ino` firmware file.
3. Ensure the `diagram.json` reflects the custom "Right-Side GPIO Topology" utilized in this project.
4. Press **Play** to initiate the non-blocking logic loop.
5. Interact with the DHT22 and LDR sliders to trigger autonomous actuations.

**Developed by:** Bharath M.  
*Final Year IoT Engineering Project*
