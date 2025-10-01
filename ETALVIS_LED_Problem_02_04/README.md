# Problem 4: LEDs on Port C Bits 0–7 Glow One at a Time

**Objective:**  
Connect eight LEDs to Port C, Bits 0 to 7, and glow them **one by one**, ensuring that **only one LED is ON at a time**.

**Files Included:**  
- `src/sketch.ino` → Main code to glow LEDs sequentially  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link (Optional):**  
[Open in Wokwi](https://wokwi.com/projects/443597373226578945)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see LEDs glow sequentially from Bit 0 to Bit 7, one LED at a time.

**Expected Output:**  
- LED at Port C, Bit 0 glows first.  
- Then it turns OFF and LED at Bit 1 glows.  
- Continue sequentially until Bit 7 glows.  
- Only **one LED is ON at any given time**.
