*This project has been created as part of the 42 curriculum by mbadarin, kalnajja.*

# PUSH_SWAP

## A 42 Amman Porject

### Tbale of contents
1. [Description](#description)
2. [Instructions](#instructions)
   1. [Makefile instructions](#makefile-instructions)
   2. [Programme use](#programme-use)
      1. [Valid strategy flags](#valid-strategy-flags)
      2. [Benchmark flag](#benchmark-flag)
      3. [Input stack rules](#input-stack-rules)
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
5. [Bonus (checker)](#bonus-checker)
6. [Work division](#work-division)

<hr/>

### Description

A program that sorts a stack of integers utilising several algorithims based on a disroder metric.
<hr/>

### Instructions
#### Makefile instructions
To compile the program, run:
```
make
#OR
make all
```
To remove the compiled files run:
```
#To remove object files only
make clean
#To remove object files AND the executable
make fclean
```
To perform a clean compilation run:
```
make re
#equivalent to make fclean all
```
To compile the checker (bonus) run:
```
make bonus
```
<hr/>

#### Programme use
The syntax for running the program is as follows:
```
./push_swap [STRATEGY FLAG: optional] [BENCHMARK FLAG: optional] [INPUT STACK]
```
The syntax for using the checker (bouns) is as follows:
```
./checker [INPUT STACK] < [OPERATIONS]
```
##### Valid strategy flags
| Flag | Function |
| ---- | -------- |
| --adaptive | Uses a strategy based on input stack disorder. (Default) |
| --simple | Forces the use of the simple algorithm. |
| --medium | Forces the use of the medium algorithm. |
| --complex | Forces the use of the complex algorithm. |

##### Benchmark flag
- "**--bench**": see details [below](#benchmark-mode---bench)

##### Input stack rules
The input stack should be entered in a sequential manner and separated by a single white space, where the first element on the left dentoing the top of the stack. Valid input range is -2,147,483,648 (*INT_MIN*) to 2,147,483,647 (*INT_MAX*).

Useage examples:
```
#generates and prints a list of operations to sort the stack using the adaptive, disorder-based strategy
#  4
#  2
#  1
#  6
#Stack
./push_swap 4 2 1 6
```
```
#generates and benchmarks operations to sort the stack
./push_swap --bench 4 2 1 6
```
```
#generates and prints a list of operations to sort the stack using the medium strategy
ARGS="4 2 1 6"; ./push_swap --medium $(cat ARGS)
```
```
#use the checker to validate the output of push_swap
ARGS="4 2 1 6"; ./push_swap $ARGS 1> ops.txt; ./checker $ARGS < ops.txt
```
<hr/>

### Resources
<hr/>

#### Use of AI
<hr/>

### Detailed description

The program by default chooses the algorithm to run based on the disorder of the input stack. The program prints the operations generated to sort the stack into stdout *(fd 1)* separated by newlines.

In case the program encountered an error, such as the input stack is an int outside the valid int range or is not numeric, the program exits and displays an "*Error*" message.

The below modes can be used to override the default behaviour, i.e. force the use of a specific strategy and enable benchmark mode.
<hr/>

#### Disorder

The stack's disorder is calculated based on the number of pairs and number of mistakes. A pair is defined as two numbers sequentially (which translates to size of stack - 1), and a mistake is defined as a larger number followed by a smaller one.
<hr/>

#### Modes

##### Adaptive mode --adaptive (default)

Based on calcualted disorder, simple, medium, or complex strategy is used to generate the sorting operations.

| Disorder | Strategy |
| -------- | -------- |
| disorder \< 20%: | simple |
| 20% \<= disorder \< 50%: | medium |
| 50% =\< disorder: | complex |
<hr/>

##### Simple mode (O(n²)) --simple

Stack *a* is looped over once and the smaller of the two top numbers is sent to stack *b*, then loops over stack *b* and sorts it in descending order.

The algorithm loops until only one value is left in *a*, which is the largest by definition. Then *b* which is perfectly sorted in descending order is pushed to *a*, flipping the order and leaving *a* perfectly sorted in ascending order.

The time complexity of this algorithm is O(n²) because it compares each element in *a* with the entire stack *b*.
<hr/>

##### Medium mode (O(n√n)) --medium
<hr/>

##### Complex mode (O(nlog(n))) --complex
<hr/>

##### Benchmark mode --bench

Displays the disorder as a percentage, the strategy used (including the comlexity expressed in BigO notation), the total number of operations performed, and the tally of operations used.

By default, the benchmark output is directed towards stderr *(fd 2)*, but enabling the benchmark mode routes its towards stdout *(fd 1)* and suppresses the printing of the operations generated.
<hr/>

### Bonus (checker)

The bonus part consists of a checker program that takes as arguments the unordered stack and a set of operations separated by newlines through stdin *(fd 0)*. The program then displays "*OK*" if the stack is ordered after applying the operations, "*KO*" in case it is not, and "*ERROR*" in case it encounted an error.
<hr/>

### Work division
The work was divided between the two students as follows:
| Task | Handled By |
| ---- | ---------- |
| Infrastructure and basic operations behaviour | **mbadarin** |
| Disroder logic | **kalnajja** |
| Simple algorithm | **mbadarin** |
| Medium algorithm | **kalnajja** |
| Complex algorithm | **kalnajja** |
| Checker | **mbadarin** |
| Documentation | **mbadarin** and **kalnajja** |
<hr/>