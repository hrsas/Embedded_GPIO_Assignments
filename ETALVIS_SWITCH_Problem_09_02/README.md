# Problem 2: Press 3rd Switch to Sequentially Glow 3rd, 1st, 7th, and 4th LEDs

**Objective:**  
Connect 8 LEDs on Port A and 8 push button switches on Port B.  
When the **3rd switch** (PB2) is pressed, glow LEDs **3rd, 1st, 7th, and 4th** sequentially with delays in between.

**Files Included:**  
- `src/sketch.ino` → Main program controlling LED sequence  
- `wokwi/diagram.json` → Circuit setup for Port A and Port B  
- `wokwi/wokwi-project.txt` → Wokwi project metadata  

**Simulation Link:**  
[Open in Wokwi](https://wokwi.com/projects/444040985932000257)

**Steps to Run:**  
1. Open the sketch in Wokwi.  
2. Press the 3rd switch.  
3. LEDs 3, 1, 7, and 4 glow one by one with visible delay.

**Expected Output:**  
- Press 3rd switch → LEDs light up in order: 3 → 1 → 7 → 4.  
- Each LED turns off before the next one lights.  
- Sequence repeats if button is pressed again.
