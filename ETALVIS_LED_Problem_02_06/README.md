# Problem 6: LEDs on Port K Bits 0–7 Glow Odd LEDs One by One

**Objective:**  
Connect eight LEDs to Port K, Bits 0 to 7, and glow only the **odd-position LEDs** (Bits 1, 3, 5, 7) **one by one**, without turning off the previous LEDs.

**Files Included:**  
- `src/sketch.ino` → Main code to glow odd LEDs sequentially  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link (Optional):**  
[Open in Wokwi](https://wokwi.com/projects/443598416172036097)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see the odd LEDs (Bits 1, 3, 5, 7) glow sequentially, each staying ON.

**Expected Output:**  
- LED at Bit 1 glows first.  
- Then Bit 3 glows while Bit 1 stays ON.  
- Continue sequentially for Bits 5 and 7.  
- All odd LEDs remain lit at the end.  
- Even LEDs (Bits 0, 2, 4, 6) stay OFF.
