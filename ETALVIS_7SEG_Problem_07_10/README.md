# Problem 10: Display 0.000 to 999.9 Using Four 7-Segment Displays (0.1 Increment)

**Objective:**  
Connect **four 7-segment displays** to **Port A**, with **common pins** connected to **Bits 0, 1, 2, and 3** of **Port B**, and display numbers **0.000 to 999.9**, incrementing by **0.1**.

**Files Included:**  
- `src/sketch.ino` → Code for 0.000–999.9 display  
- `wokwi/diagram.json` → 4-digit multiplexed 7-segment circuit  
- `wokwi/wokwi-project.txt` → Wokwi reference  

**Simulation Link:**  
[Open in Wokwi](https://wokwi.com/projects/443893084507497473)

**Steps to Run:**  
1. Load the code and ensure proper wiring for multiplexed displays.  
2. Observe the counting with decimal accuracy.  

**Expected Output:**  
- Display counts smoothly from **0.000 → 0.100 → ... → 999.9**  
- Decimal point is fixed between digits for precision display.  
