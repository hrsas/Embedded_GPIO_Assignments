# Problem 3: LEDs on Port B Bits 0–7 Glow One by One

**Objective:**  
Connect eight LEDs to Port B, Bits 0 to 7, and glow them **one by one**, without turning off the previous LEDs.

**Files Included:**  
- `src/sketch.ino` → Main code to glow LEDs sequentially  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link (Optional):**  
[Open in Wokwi](https://wokwi.com/projects/443597115889181697)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see LEDs glow sequentially from Bit 0 to Bit 7, each staying ON.

**Expected Output:**  
- LED at Port B, Bit 0 glows first.  
- Then LED at Bit 1 glows while Bit 0 stays ON.  
- Continue sequentially until Bit 7 is ON.  
- At the end, all 8 LEDs remain lit.
