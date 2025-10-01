# Problem 5: LEDs on Port F Bits 0–7 Glow Even LEDs One by One

**Objective:**  
Connect eight LEDs to Port F, Bits 0 to 7, and glow only the **even-position LEDs** (Bits 0, 2, 4, 6) **one by one**, without turning off the previous LEDs.

**Files Included:**  
- `src/sketch.ino` → Main code to glow even LEDs sequentially  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link (Optional):**  
[Open in Wokwi](https://wokwi.com/projects/443598193857038337)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see the even LEDs (Bits 0, 2, 4, 6) glow sequentially, each staying ON.

**Expected Output:**  
- LED at Bit 0 glows first.  
- Then Bit 2 glows while Bit 0 stays ON.  
- Continue sequentially for Bits 4 and 6.  
- All even LEDs remain lit at the end.  
- Odd LEDs (Bits 1, 3, 5, 7) stay OFF.
