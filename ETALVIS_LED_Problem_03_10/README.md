# Problem 10: LEDs on Port A Bits 0–7 Glow Decrementally (7 to 7-0)

**Objective:**  
Connect eight LEDs to Port A, Bits 0 to 7, and glow LEDs decrementally with delay:  
- First LED 7  
- Then LEDs (7,6)  
- Then (7,6,5)  
- … until (7,6,5,4,3,2,1,0)

**Files Included:**  
- `src/sketch.ino` → Main code for decremental glow  
- `wokwi/diagram.json` → Wokwi circuit diagram  
- `wokwi/wokwi-project.txt` → Project source info

**Simulation Link :**  
[Open in Wokwi](https://wokwi.com/projects/443681365108546561)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Run the simulation to see LEDs accumulate ON from bit 7 down to bit 0 with delays.

**Expected Output:**  
- LEDs progressively turn ON: 7 → (7,6) → (7,6,5) → … → (7..0).  
- Each step is separated by a visible delay.
