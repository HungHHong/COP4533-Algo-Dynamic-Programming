# Programming Assignment 3 – Highest Value Longest Common Sequence

## Course & Authors
* **Course:** COP 4533 – Algorithm Abstraction and Design (University of Florida)
* **Team Members:**
    * Hung Hong (UFID: 56253262)
    * Thyssen Nicholas (UFID: 19705329)

**Contributions**
- Part A (Matcher): Hung Hong  
- Part B (Verifier): Thyssen Nicholas  


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
│   ├── dp_solver.cpp
│   ├── dp_solver.h
│   ├── reconstruct.cpp
│   ├── reconstruct.h
│   └── parser.cpp
│
├── data/               # Input files
│   ├── example.in
│   ├── test1.in
│   ├── test2.in
│   └── ...
│
├── result/             # Output files
│   ├── example.out
│   ├── test1.out
│   └── ...
│
├── experiments/  
│   ├── runtimes.csv
│   └── graph.png
│
├── README.md
└── Makefile

```


