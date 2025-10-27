# Problem 1: Display "ETAL" Entering from Bottom in 3s, Stay 10s, Exit Left in 4s

**Objective:**  
Animate the text **ETAL** on the MAX7219 Dot Matrix connected to Port A such that it:  
- Enters from **bottom** in **3 seconds**,  
- Stays visible for **10 seconds**,  
- Leaves by moving to the **left** in **4 seconds**.

**Files Included:**  
- `src/sketch.ino` → Code for bottom-entry, timed stay, left-exit  
- `wokwi/diagram.json` → MAX7219 circuit setup  
- `wokwi/wokwi-project.txt` → Simulation metadata  

**Simulation Link :**  
[Open in Wokwi](https://wokwi.com/projects/445903302241052673)

**Steps to Run:**  
1. Upload `sketch.ino` in Wokwi.  
2. Start simulation.  
3. Observe entry, pause, and exit animation.

**Expected Output:**  
- “ETAL” scrolls **upward from bottom** in 3s.  
- Holds steady for 10s.  
- Scrolls **out to the left** in 4s.
