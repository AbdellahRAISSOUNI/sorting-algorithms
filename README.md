# Sorting Algorithms and Tower of Hanoi

This project provides implementations of various sorting algorithms and the Tower of Hanoi problem in C. The sorting algorithms included are bubble sort, selection sort, insertion sort, quicksort, and merge sort. The Tower of Hanoi algorithm is also implemented.

### Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [How to Use](#how-to-use)
4. [Sorting Algorithms](#sorting-algorithms)
5. [Tower of Hanoi](#tower-of-hanoi)
6. [Contributing](#contributing)
7. [License](#license)

### Introduction
This project aims to provide a comprehensive collection of sorting algorithms and a classic problem from computer science, the Tower of Hanoi, implemented in C. It allows users to interactively perform sorting operations on numbers read from files or generated randomly and observe the execution times.

### Features
- Generate random numbers and save them to a file.
- Read numbers from a file.
- Perform sorting using various algorithms: bubble sort, selection sort, insertion sort, quicksort, and merge sort.
- Solve the Tower of Hanoi problem for any number of disks.

### How to Use
1. Clone the repository to your local machine.
   ```bash
   git clone https://github.com/your_username/sorting-tower-of-hanoi.git
   ```
2. Compile the `sorting-tower-of-hanoi.c` file using a C compiler such as GCC.
   ```bash
   gcc sorting-tower-of-hanoi.c -o sorting-tower-of-hanoi
   ```
3. Run the compiled executable.
   ```bash
   ./sorting-tower-of-hanoi
   ```
4. Follow the on-screen instructions to perform various operations.

### Sorting Algorithms
- **Bubble Sort**: Compares adjacent elements and swaps them if they are in the wrong order.
- **Selection Sort**: Repeatedly selects the minimum element from the unsorted portion and places it at the beginning.
- **Insertion Sort**: Builds the sorted array one element at a time by repeatedly taking the next element and inserting it into its correct position.
- **Quicksort**: Divides the array into two sub-arrays around a pivot element such that elements smaller than the pivot are on the left and larger on the right. Recursively sorts the sub-arrays.
- **Merge Sort**: Divides the array into two halves, recursively sorts them, and then merges the sorted halves.

### Tower of Hanoi
The Tower of Hanoi is a mathematical puzzle that consists of three rods and a number of disks of different sizes which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top. The objective of the puzzle is to move the entire stack to another rod, obeying the following rules:
1. Only one disk can be moved at a time.
2. Each move consists of taking the top disk from one stack and placing it on another stack.
3. No disk may be placed on top of a smaller disk.

### Contributing
Contributions are welcome! If you have suggestions, bug reports, or enhancements, please open an issue or create a pull request on the GitHub repository.

### License
This project is licensed under the [MIT License](LICENSE).

---

Feel free to reach out with any questions or feedback! Enjoy sorting and solving the Tower of Hanoi!
