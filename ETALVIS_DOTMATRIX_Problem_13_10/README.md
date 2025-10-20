# Problem 10: Display "WELCOME" with Odd Positions Entering from Top and Even Positions from Bottom

**Objective:**  
Animate the word **WELCOME** such that:  
- Odd-positioned characters appear from the **top**,  
- Even-positioned characters appear from the **bottom**,  
and meet in the center of the 8x8 LED Dot Matrix.

**Files Included:**  
- `src/sketch.ino` → Code for top-bottom merging text animation  
- `wokwi/diagram.json` → 8x8 display wiring  
- `wokwi/wokwi-project.txt` → Wokwi simulation data  

**Simulation Link:**  
[Open in Wokwi](https://wokwi.com/projects/445355477154997249)

**Steps to Run:**  
1. Upload `sketch.ino` to Wokwi.  
2. Run simulation to view animation.  
3. Adjust delays if synchronization needs tuning.

**Expected Output:**  
- Odd-positioned letters (W, L, O, E) move **downward from top**.  
- Even-positioned letters (E, C, M) move **upward from bottom**.  
- They align together to form **WELCOME** dynamically.
