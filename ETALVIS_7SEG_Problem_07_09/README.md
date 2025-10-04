# Problem 9: Display 0000 to 9999 Using Four 7-Segment Displays (0.1s Delay)

**Objective:**  
Connect **four 7-segment displays** to **Port A**, with **common pins** connected to **Bits 0, 1, 2, and 3** of **Port B**, and display numbers **0000 to 9999** with a **0.1-second delay**.

**Files Included:**  
- `src/sketch.ino` → Counter code for 0000–9999  
- `wokwi/diagram.json` → Four-display multiplexed circuit  
- `wokwi/wokwi-project.txt` → Project metadata  

**Simulation Link:**  
[Open in Wokwi](https://wokwi.com/projects/443891772855169025)

**Steps to Run:**  
1. Run the simulation to see continuous counting.  
2. Each digit updates using multiplexing control.  

**Expected Output:**  
- Displays increment in real-time from **0000** to **9999**, refreshing every 0.1s.  
