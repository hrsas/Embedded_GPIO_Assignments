# Problem 8: LEDs on Port F Bits 0–7 Glow Bits 4 to 7 One by One

**Objective:**  
Connect eight LEDs to Port F, Bits 0 to 7, and glow **only LEDs at Bits 4, 5, 6, and 7** sequentially, **one at a time**.

**Files Included:**  
- `src/sketch.ino` → Main code to glow LEDs sequentially  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link (Optional):**  
[Open in Wokwi](https://wokwi.com/projects/443598862366434305)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see LEDs at Bits 4, 5, 6, 7 glow sequentially, one LED at a time.

**Expected Output:**  
- LED at Bit 4 glows first.  
- Then Bit 5 glows while Bit 4 turns OFF.  
- Continue sequentially for Bits 6 and 7.  
- At any moment, only **one LED is ON**.  
- LEDs at Bits 0–3 remain OFF.
