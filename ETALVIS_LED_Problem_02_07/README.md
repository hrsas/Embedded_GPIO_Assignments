# Problem 7: LEDs on Port L Bits 0–7 Glow Bits 0 to 3 One by One

**Objective:**  
Connect eight LEDs to Port L, Bits 0 to 7, and glow **only LEDs at Bits 0, 1, 2, and 3** sequentially, **one at a time**.

**Files Included:**  
- `src/sketch.ino` → Main code to glow LEDs sequentially  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link (Optional):**  
[Open in Wokwi](https://wokwi.com/projects/443598671028517889)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see LEDs at Bits 0, 1, 2, 3 glow sequentially, one LED at a time.

**Expected Output:**  
- LED at Bit 0 glows first.  
- Then Bit 1 glows while Bit 0 turns OFF.  
- Continue sequentially for Bits 2 and 3.  
- At any moment, only **one LED is ON**.  
- LEDs at Bits 4–7 remain OFF.
