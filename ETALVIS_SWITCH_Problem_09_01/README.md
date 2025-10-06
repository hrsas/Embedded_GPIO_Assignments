# Problem 1: Press 2nd Switch to Sequentially Glow 1st, 2nd, 5th, and 6th LEDs

**Objective:**  
Connect 8 LEDs on Port A and 8 push button switches on Port B.  
When the **2nd switch** (PB1) is pressed, glow LEDs **1st, 2nd, 5th, and 6th** one after another with a delay between each.

**Files Included:**  
- `src/sketch.ino` → Code to control LED glowing sequence  
- `wokwi/diagram.json` → Wokwi circuit diagram for Port A & Port B connections  
- `wokwi/wokwi-project.txt` → Wokwi project metadata  

**Simulation Link:**  
[Open in Wokwi](https://wokwi.com/projects/444040866632329217)

**Steps to Run:**  
1. Open the project in Wokwi.  
2. Press the 2nd switch connected to Port B.  
3. Observe LEDs on Port A glowing sequentially (1st → 2nd → 5th → 6th).  

**Expected Output:**  
- When 2nd switch is pressed:  
  - 1st LED glows, delay  
  - 2nd LED glows, delay  
  - 5th LED glows, delay  
  - 6th LED glows, delay  
- After the sequence, all LEDs turn OFF.
