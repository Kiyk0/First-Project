# Circuit Analyzer

This project analyzes circuits by allowing the processing of mixed connection types in electrical circuits, calculating the total resistance and the circuit current.

## Project Overview

The objective of this project is to make C++ program to:
- **Parse a single circuit description string:**  
  The string includes connection types (Series: `S`, Parallel: `P`), resistance values, group delimiters (`e` for ending a group), and an overall end marker (`E`).
- **Process Mixed Connection Types:**  
  Handle circuits that involve both series and parallel combinations within the same description.
- **Calculate Total Resistance:**  
  Use modular programming by implementing separate user-defined functions for series and parallel resistance calculations.
- **Compute Circuit Current:**  
  With the provided applied voltage, calculate the current flowing through the circuit.
- **Error Handling:**  
  Validate the circuit description and output a warning message ("Wrong Circuit Description") if an invalid connection type is encountered.

## Key Features

- **String Processing:**  
  The program parses the user input string to extract connection types and resistance values using functions like `strtok()`.
  
- **Modular Design:**  
  Separate functions are implemented for calculating resistance in series and parallel configurations.
  
- **Robust Error Handling:**  
  Ensures that only valid connection types are processed and notifies the user of any incorrect descriptions.
  
- **Comprehensive Circuit Analysis:**  
  Calculates both the total resistance and the circuit current based on the applied voltage.

## Example Test Cases

1. **Input:**  
   - Circuit description: `S 1.5 P S 12.85 3.6 e 5 6.6 e 7 E`  
   - Voltage applied: `3.8`
2. **Input:**  
   - Circuit description: `S L 2.5 5.2 e 4.7 8 E`  
   - Voltage applied: `9`
3. **Input:**  
   - Circuit description: `P S 4.7 4.7 e 4.7 S 4.7 4.7 e E`  
   - Voltage applied: `7`
4. **Input:**  
   - Circuit description: `P S 4.7 4.7 e 4.7 4.7 E`  
   - Voltage applied: `9`
5. **Input:**  
   - Circuit description: `Z S 8.2 3.1 e 1.3 7.8 E`  
   - Voltage applied: `5`
6. **Input:**  
   - Circuit description: `P S 8.2 3.1 e S 1.3 7.8 e E`  
   - Voltage applied: `5`

## How to Run

1. **Compile the Program:**  
   Use a C++ compiler (e.g., g++) to compile the code:
   ```bash
   g++ main.cpp -o circuit_analyzer

2. **Run the Executable:**  
   Execute the compiled program:
   ```bash
   ./circuit_analyzer

3. **Compile the Program:**  
   Input the Circuit Description and Voltage:
   Enter the circuit description string and the applied voltage as prompted.
