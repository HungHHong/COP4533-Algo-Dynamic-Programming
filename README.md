# Programming Assignment 3 – Highest Value Longest Common Sequence

## Course & Authors
* **Course:** COP 4533 – Algorithm Abstraction and Design (University of Florida)
* **Team Members:**
    * Hung Hong (UFID: 56253262)
    * Thyssen Nicholas (UFID: 19705329)

**Contributions**
Hung Hong: DP_Solver
Thyssen Nicholas: main, generator


## Overview
- Highest Value Longest Common Subsequence (HVLCS)
- Given 2 strings + value for each character
- Find subsequence with maximum total value

## Core Tasks
- Parse input (K, values, A, B)
- Compute DP table
- Get max value
- Reconstruct subsequence
- Print result

## Algorithm
- DP (similar to LCS but weighted)
- Handle match vs skip

## Experiments
- 10+ test cases
- Strings length ≥ 25
- Measure runtime
- Plot graph

## Written
- Recurrence + base case
- Explain correctness
- Pseudocode
- Time complexity

## Files
- Example input/output
- Test inputs



intented profile file setup
Project file
```
│
├── src/     
│   ├── main.cpp
│   └── dp_solver.cpp
│
├── data/               # Input/output files
│   ├── example.in
│   ├── input[#].in
│   ├── output[#].out
│   └── ...
│
├── experiments/       # Data from Exeriments
│   ├── runtimes.csv
│   └── graph.png
│
└── README.md


```

# How to run
run with given test input
g++ -std=c++17 src/main.cpp -o hvlcs
Get-Content data/input_.in | ./hvlcs

# Question 1:

input1.in trough input10.in are all non trivial input files that we randomly generated. These files varied in input size, by having different alphabet lengths, lengths of A and lengths of B. We were able to use the main to solve these input files and get their running times for each in respect to length of A * length of B.

![Recurrence](experiments/graph.png)

# Question 2: 
Recurrence equation

![Recurrence](experiments/OverLeaf_Algo%20DP_P3_Q2.png)

- Base case: If either string is empty, the value is 0.
- Case 1: If A[i] = B[j], we consider including the character or skipping from either string.
- Case 2: If A[i] ≠ B[j], we skip one character from either string.


# Question 3: