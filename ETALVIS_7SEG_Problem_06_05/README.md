# Problem 5: Common Anode Display 0–9 and 9–0 with 1 Second Delay

**Objective:**  
Connect a **common anode 7-segment display** to Port A and display digits **0–9** then **9–0**, sequentially with a **1-second delay**.

**Files Included:**  
- `src/sketch.ino` → Main code for 0–9 and 9–0  
- `wokwi/diagram.json` → Wokwi circuit diagram for the setup  
- `wokwi/wokwi-project.txt` → Original Wokwi project information/source

**Simulation Link:**  
[Open in Wokwi](https://wokwi.com/projects/443766033813269505)

**Steps to Run:**  
1. Open `sketch.ino` in Wokwi.  
2. Load `diagram.json` if needed.  
3. Run the simulation to see digits 0 → 1 → … → 9 → 8 → … → 0 appear.

**Expected Output:**  
- Display counts up 0–9, then counts down 9–0.  
- Each digit is displayed for **1 second**.
