*This project has been created as part of the 42 curriculum by mbadarin, kalnajja.*

# PUSH_SWAP

## A 42 Amman Porject

### Tbale of contents
1. [Description](#description)
2. [Instructions](#instructions)
3. [Resources](#resources)
   - [Use of AI](#use-of-ai)
4. [Detailed description](#detailed-description)
   1. [Disorder](#disorder)
   2. [Modes](#modes)
      1. [Adaptive mode](#adaptive-mode---adaptive-default)
      2. [Simple](#simple-mode-on---simple)
      3. [Medium mode](#medium-mode-onn---medium)
      4. [Complex mode](#complex-mode-onlogn---complex)
      5. [Benchmark mode](#benchmark-mode---bench)

### Description

A program that sorts a stack of integers utilising several algorithims based on a disroder metric.

### Instructions

### Resources

#### Use of AI

### Detailed description

The program by default chooses the algorithm to run based on the disorder of the input stack. The program prints the operations generated to sort the stack into stdout *(fd 1)* separated by newlines.

The below modes can be used to override the default behaviour, i.e. force the use of a specific strategy and enable benchmark mode.

#### Disorder

The stack's disorder is calculated based on the number of pairs and number of mistakes. A pair is defined as two numbers sequentially (which translates to size of stack - 1), and a mistake is defined as a larger number followed by a smaller one.

#### Modes

##### Adaptive mode --adaptive (default)

Based on calcualted disorder, simple, medium, or complex strategy is used to generate the sorting operations.

| Disorder | Strategy |
| -------- | -------- |
| disorder \< 20%: | simple |
| 20% \<= disorder \< 50%: | medium |
| 50% =\< disorder: | complex |

##### Simple mode (O(n²)) --simple

Stack *a* is looped over once and the smaller of the two top numbers is sent to stack *b*, then loops over stack *b* and sorts it in descending order.

The algorithm loops until only one value is left in *a*, which is the largest by definition. Then *b* which is perfectly sorted in descending order is pushed to *a*, flipping the order and leaving *a* perfectly sorted in ascending order.

##### Medium mode (O(n√n)) --medium

##### Complex mode (O(nlog(n))) --complex

##### Benchmark mode --bench

Displays the disorder as a percentage, the strategy used (including the comlexity expressed in BigO notation), the total number of operations performed, and the tally of operations used.

By default, the benchmark output is directed towards stderr *(fd 2)*, but enabling the benchmark mode routes its towards stdout *(fd 1)* and suppresses the printing of the operations generated.