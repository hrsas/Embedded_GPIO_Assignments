# Problem 3: Press 2nd Switch to Sequentially Glow 0th, 1st, 5th, and 6th LEDs

**Objective:**  
Connect 8 LEDs to Port A and 8 switches to Port B.  
When the **2nd switch** (PB1) is pressed, glow **LEDs 0, 1, 5, and 6** with a short delay between each.

**Files Included:**  
- `src/sketch.ino`  
- `wokwi/diagram.json`  
- `wokwi/wokwi-project.txt`  

**Simulation Link:**  
[Open in Wokwi](https://wokwi.com/projects/444041082850873345)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Press the 2nd switch.  
3. LEDs at bits 0, 1, 5, and 6 glow in order.

**Expected Output:**  
- LED 0 glows → delay  
- LED 1 glows → delay  
- LED 5 glows → delay  
- LED 6 glows → delay  
- All LEDs off after sequence.
