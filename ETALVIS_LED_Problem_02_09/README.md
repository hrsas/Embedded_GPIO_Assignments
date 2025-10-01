# Problem 9: LEDs on Port F Bits 0–7 Glow Bits 3 to 0 One by One

**Objective:**  
Connect eight LEDs to Port F, Bits 0 to 7, and glow **only LEDs at Bits 3, 2, 1, and 0** sequentially, **one at a time**, starting from Bit 3 down to Bit 0.

**Files Included:**  
- `src/sketch.ino` → Main code to glow LEDs sequentially  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link (Optional):**  
[Open in Wokwi](https://wokwi.com/projects/443599014016781313)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see LEDs at Bits 3, 2, 1, 0 glow sequentially, one LED at a time.

**Expected Output:**  
- LED at Bit 3 glows first.  
- Then Bit 2 glows while Bit 3 turns OFF.  
- Continue sequentially for Bits 1 and 0.  
- At any moment, only **one LED is ON**.  
- LEDs at Bits 4–7 remain OFF.
