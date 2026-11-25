*This project has been created as part of the 42 curriculum by mbadarin, kalnajja.*

# PUSH_SWAP

## A 42 Amman Project

### Description

A program that sorts a stack of integers utilising several algorithms based on a disorder metric.
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
The syntax for using the checker (bonus) is as follows:
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
The input stack should be entered in a sequential manner and separated by a single white space, where the first element on the left denoting the top of the stack. Valid input range is -2,147,483,648 (*INT_MIN*) to 2,147,483,647 (*INT_MAX*).

Usage examples:
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

- [Grokking Algorithms](https://github.com/agrism/books/blob/master/Grokking%20Algorithms%20-%20An%20illustrated%20guide%20for%20programmers%20and%20other%20curious%20people.pdf): Introductory book on algorithms.
- [GeeksforGeeks.com](https://www.geeksforgeeks.org/dsa/3-way-quicksort-dutch-national-flag/): 3-way algorithm (used for complex option)
- [Medium.com](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81): Chunk-merge algorithm (used for medium option)
<hr/>

#### Use of AI

Use of AI was limited to explaining the overall concepts, using a json file containing the following data as instructions to ensure no ready solutions are gives:
- [AI Instructions (JSON file)](./AI_instructions.json)
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

Based on calculated disorder, simple, medium, or complex strategy is used to generate the sorting operations.

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

The algorithm first assigns an index to each element using Coordinate Compression. Each element receives an index based on its relative position in the sorted order, allowing the algorithm to work with indices instead of the original values.

It then determines the chunk window size based on the number of elements:

- 15 for inputs containing up to 100 elements.
- 30 for inputs containing more than 100 elements.

The algorithm distributes elements from stack *a* to stack *b* using a moving window controlled by two variables:

- **PUSHED:** tracks the number of elements transferred from stack *a* to stack *b*.
- **CHUNK:** determines the width of the current index window.

For each element at the top of stack *a*:

- If its index is less than or equal to PUSHED, it is pushed to stack *b* using `pb`, then rotated using `rb` to move smaller elements toward the bottom of stack *b*.
- If its index is within the current window (PUSHED + CHUNK), it is pushed to stack *b* using `pb` without rotation.
- Otherwise, stack *a* is rotated using `ra` to inspect the next element.

This process continues until all elements have been transferred from stack *a* to stack *b*.

Once stack *a* is empty, the algorithm rebuilds the sorted stack by repeatedly finding the maximum index in stack *b*, bringing it to the top using the shortest rotation direction (`rb` or `rrb`), and moving it back to stack *a* using `pa`.

By repeatedly moving the maximum remaining element to stack *a*, the algorithm builds the final stack in ascending order.

The chunk distribution strategy aims to reduce the number of operations by keeping larger elements closer to the top of stack *b*, while moving smaller elements toward the bottom. The chunk size is a tuning parameter and may require adjustment depending on the input size and operation results.

The sorting phase is expected to perform around **O(n²)** operations in the worst case, since finding the maximum index in stack *b* and bringing it to the top are repeated for each element. Coordinate Compression also currently takes **O(n²)** due to its implementation.
<hr/>

##### Complex mode (O(nlog(n))) --complex

The algorithm first assigns an index to each element using Coordinate Compression. Each element receives an index based on its relative position in the sorted order, allowing the algorithm to work with indices instead of the original values.

It then divides the current segment into three groups using two partition boundaries:
- MIN: the lowest 42% of the segment.
- MIDDLE: the middle 16% of the segment.
- MAX: the highest 42% of the segment.

Elements are distributed between stacks *a* and *b* according to their group and current location. The algorithm uses rotations and push operations to organize each group in the appropriate stack position.

Each group is then recursively processed using the same three-way partitioning strategy until its size becomes small enough to be handled by dedicated base-case sorting functions.

The base cases handle segments containing up to two elements. Once a segment is sorted, its elements are moved back to stack *a* when necessary. The recursive process continues until all segments are sorted and combined, leaving stack *a* in ascending order.

The partitioning process has an **O(n log n)** Push_swap operation complexity. Each recursion level processes all elements in its segments once, while the number of levels grows logarithmically as the segments become smaller.

However, the complete implementation has additional execution overhead. Coordinate Compression currently takes O(n²), and the linked-list operations and operation logging also introduce extra processing time.
<hr/>

##### Benchmark mode --bench

Displays the disorder as a percentage, the strategy used (including the complexity expressed in BigO notation), the total number of operations performed, and the tally of operations used.

By default, the benchmark output is directed towards stderr *(fd 2)*, but enabling the benchmark mode routes its towards stdout *(fd 1)* and suppresses the printing of the operations generated.
<hr/>

### Bonus (checker)

The bonus part consists of a checker program that takes as arguments the unordered stack and a set of operations separated by newlines through stdin *(fd 0)*. The program then displays "*OK*" if the stack is ordered after applying the operations, "*KO*" in case it is not, and "*ERROR*" in case it encountered an error.
<hr/>

### Work division
The work was divided between the two students as follows:
| Task | Handled By |
| ---- | ---------- |
| Infrastructure and basic operations behaviour | **mbadarin** |
| Disorder logic | **kalnajja** |
| Simple algorithm | **mbadarin** |
| Medium algorithm | **kalnajja** |
| Complex algorithm | **kalnajja** |
| Checker | **mbadarin** |
| Documentation | **mbadarin** and **kalnajja** |
<hr/>