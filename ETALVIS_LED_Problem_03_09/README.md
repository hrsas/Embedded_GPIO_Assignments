# Problem 9: LEDs on Port A Bits 0–7 Glow Incrementally (0 to 0-7)

**Objective:**  
Connect eight LEDs to Port A, Bits 0 to 7, and glow LEDs incrementally with delay:  
- First LED 0  
- Then LEDs (0,1)  
- Then (0,1,2)  
- … until (0,1,2,3,4,5,6,7)

**Files Included:**  
- `src/sketch.ino` → Main code for incremental glow  
- `wokwi/diagram.json` → Wokwi circuit diagram  
- `wokwi/wokwi-project.txt` → Project source info

**Simulation Link :**  
[Open in Wokwi](https://wokwi.com/projects/443681222666800129)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Run the simulation to see LEDs accumulate ON from bit 0 up to bit 7 with delays.

**Expected Output:**  
- LEDs progressively turn ON: 0 → (0,1) → (0,1,2) → … → (0..7).  
- Each step is separated by a visible delay.
