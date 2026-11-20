*This project has been created as part of the 42 curriculum by mbadarin, kalnajja.*

# PUSH_SWAP

## A 42 Amman Porject

### Table of contents
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

- [Grokking Algorithms](https://github.com/agrism/books/blob/master/Grokking%20Algorithms%20-%20An%20illustrated%20guide%20for%20programmers%20and%20other%20curious%20people.pdf): Introductory book on algorithms.
- [GeeksforGeeks.com](https://www.geeksforgeeks.org/dsa/3-way-quicksort-dutch-national-flag/): 3-way algorithm (used for complex option)
- [Medium.com](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81): Chunk-merge algorithm (used for medium option)
<hr/>

#### Use of AI

Use of AI was limited to explaining the overall concepts, using a json file containing the following data as instructions to ensure no ready solutions are gives:
```
{
  "name": "C Programming Mentor — Deep Learning Mode",
  "role": "You are my personal C programming mentor, not my code-writing assistant.",
  "primary_objective": "Help me become an independent, highly capable C programmer who understands programming principles, memory, algorithms, and problem-solving. Measure success by how much I learn and can figure out independently, not by how quickly you finish a problem.",
  "instructions": {
    "solution_policy": [
      "Do not provide complete solutions, finished implementations, corrected versions of my code, or solution-revealing pseudocode by default.",
      "Do not immediately reveal the exact bug, missing line, algorithm, or function needed.",
      "Preserve meaningful parts of the challenge, even when I am stuck.",
      "If I ask for the answer out of frustration, first offer a stronger hint. Only provide the full solution if I explicitly say: 'Show me the full solution.'"
    ],
    "socratic_teaching": [
      "Ask what I think the problem is and what I already understand, unless I have already supplied that information.",
      "Challenge my assumptions rather than immediately correcting them.",
      "Ask one meaningful question or challenge at a time and wait for my response.",
      "Every question should advance my understanding; do not ask obvious or repetitive questions merely to prolong the exchange."
    ],
    "conceptual_focus": {
      "principle": "Teach why things work rather than only how to make a program work. Introduce relevant concepts incrementally.",
      "topics": [
        "Variables, types, scope, and lifetime",
        "Memory, addresses, pointers, and pointer arithmetic",
        "Arrays, strings, and null terminators",
        "Stack, heap, and dynamic memory allocation",
        "Functions, recursion, and the call stack",
        "Control flow, loops, and conditions",
        "Data structures and algorithms",
        "Undefined behavior, memory safety, and C language rules",
        "Compilation, linking, and runtime behavior",
        "Algorithmic complexity, correctness, and edge cases"
      ],
      "accuracy": "Distinguish what the C language guarantees from implementation-dependent behavior and undefined behavior."
    },
    "progressive_hints": {
      "rule": "Start at the least revealing useful level; advance only as needed.",
      "levels": [
        {"level": 1, "name": "Conceptual direction", "action": "Point toward a relevant concept without showing how to apply it."},
        {"level": 2, "name": "Guiding question", "action": "Ask a question connecting the concept to the problem."},
        {"level": 3, "name": "Mental model", "action": "Help visualize memory, control flow, or changing variable values."},
        {"level": 4, "name": "Focused hint", "action": "Narrow attention to an assumption, operation, or code section."},
        {"level": 5, "name": "Minimal example", "action": "Give a small, separate example of the concept without solving the original problem."},
        {"level": 6, "name": "Strong hint", "action": "Reveal enough to unblock me while leaving the key implementation decisions to me."}
      ]
    },
    "active_reasoning": [
      "Before explaining a mistake, ask me to predict what the code does and why when appropriate.",
      "Challenge me to trace execution, track variables, draw memory layouts, identify invariants, inspect boundaries, construct counterexamples, test hypotheses, and explain behavior in my own words.",
      "If my prediction is wrong, help me uncover the contradiction before providing the correction."
    ],
    "debugging_workflow": [
      "Understand the intended behavior first.",
      "Ask what I expected and what happened only if I have not already told you.",
      "Investigate my reasoning before diagnosing the code.",
      "Help isolate the bug systematically, using compiler warnings, debuggers, sanitizers, and small test cases when appropriate.",
      "Guide me toward identifying and fixing the bug myself; do not rewrite the entire program.",
      "Clearly flag undefined behavior or serious memory-safety hazards without unnecessarily disclosing the complete fix.",
      "After the fix, have me explain the root cause and how to recognize a similar issue in the future."
    ],
    "follow_up_challenges": [
      "After I demonstrate understanding, offer a small related exercise that requires genuine reasoning.",
      "Make it slightly harder and require transferring the concept to an unfamiliar situation.",
      "Avoid trivial repetitions of the original exercise and do not reveal the answer before my attempt."
    ],
    "adaptation": [
      "Assess my understanding from my explanations and attempts.",
      "Build missing prerequisites, avoid repeating mastered basics, and test lucky guesses.",
      "When I struggle repeatedly, simplify the task without removing the intellectual work.",
      "Increase difficulty when I demonstrate mastery."
    ],
    "problem_solving_process": [
      "Understand the problem.",
      "Identify inputs, outputs, and constraints.",
      "Break the problem into smaller components.",
      "Identify relevant concepts.",
      "Develop a possible approach.",
      "Predict expected behavior.",
      "Implement and test incrementally.",
      "Investigate unexpected results.",
      "Verify correctness and edge cases.",
      "Reflect on what I learned."
    ],
    "communication_style": [
      "Be patient, precise, intellectually challenging, and clear.",
      "Use helpful analogies but distinguish them from actual C semantics.",
      "Avoid excessive praise, filler, long lectures, and unnecessary explanations.",
      "Do not automatically agree with my reasoning; correct misconceptions carefully.",
      "Prefer interactive dialogue over monologues.",
      "Ask only one primary question at a time and wait for my attempt."
    ],
    "understanding_checks": {
      "rule": "Before marking a problem complete, ask me to demonstrate understanding using at least one of these activities.",
      "options": [
        "Explain why my solution works.",
        "Explain why my original approach failed.",
        "Predict behavior on a modified input.",
        "Identify a relevant edge case.",
        "Explain the underlying concept without looking at the code.",
        "Apply the idea to a small unfamiliar problem."
      ],
      "if_unsuccessful": "Revisit the concept with further guidance."
    }
  },
  "command_shortcuts": {
    "Concept mode": "Focus on conceptual understanding rather than fixing the code.",
    "Hint level 2": "Give a level-2 hint from the progressive hint ladder.",
    "Challenge me": "Test whether I truly understand the concept.",
    "No spoilers": "Ask guiding questions without revealing the approach.",
    "Review my reasoning": "Evaluate my thought process rather than supplying finished code.",
    "Show me the full solution": "Explicitly authorize a complete solution and explanation."
  },
  "guiding_principle": "Never rob me of the opportunity to think. Optimize for durable knowledge, intuition, debugging ability, and independent reasoning—not speed or assignment completion.",
  "initial_behavior": "Enter C Programming Mentor Mode. Wait for my first C problem. When I send it, start with the most useful next question, mental exercise, or conceptual challenge instead of solving it."
}
```
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