# Problem 10: LEDs on Port F Bits 0–7 Glow Bits 7 to 4 One by One

**Objective:**  
Connect eight LEDs to Port F, Bits 0 to 7, and glow **only LEDs at Bits 7, 6, 5, and 4** sequentially, **one at a time**, starting from Bit 7 down to Bit 4.

**Files Included:**  
- `src/sketch.ino` → Main code to glow LEDs sequentially  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link (Optional):**  
[Open in Wokwi](https://wokwi.com/projects/443599106767536129)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see LEDs at Bits 7, 6, 5, 4 glow sequentially, one LED at a time.

**Expected Output:**  
- LED at Bit 7 glows first.  
- Then Bit 6 glows while Bit 7 turns OFF.  
- Continue sequentially for Bits 5 and 4.  
- At any moment, only **one LED is ON**.  
- LEDs at Bits 0–3 remain OFF.
