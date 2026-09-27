# DSA Assignment 2 – K-Way Merge vs Pairwise Merge

## 1. Problem Statement

Given three already sorted lists, merge them into one sorted list using two different methods:

1. K-Way Merge using a Min Heap
2. Pairwise Merge

Then compare the two methods based on:
- Number of comparisons
- Heap size
- Time complexity
- Extra space
- Suitability when the number of sorted files increases

---

## 2. Input Lists

The three sorted lists are:

```text
L1 = 10 30 50 70
L2 = 20 40 60 80
L3 = 15 35 55 75
Total number of elements:

N = 12

Number of sorted lists:

K = 3
3. K-Way Merge Using Min Heap

In K-Way Merge, the smallest element from each list is inserted into a Min Heap.

Initial Heap
        10
       /  \
     20    15

The heap contains:

[10, 20, 15]

The minimum element is removed from the heap and the next element from the same list is inserted.

Process
L1: 10 → 30 → 50 → 70
L2: 20 → 40 → 60 → 80
L3: 15 → 35 → 55 → 75

             ↓

          MIN HEAP

             ↓

Sorted Output
Heap Trace
Step	Deleted	Inserted	Heap
1	10	30	[15, 20, 30]
2	15	35	[20, 30, 35]
3	20	40	[30, 35, 40]
4	30	50	[35, 40, 50]
5	35	55	[40, 50, 55]
6	40	60	[50, 55, 60]
7	50	70	[55, 60, 70]
8	55	75	[60, 70, 75]
9	60	80	[70, 75, 80]
10	70	-	[75, 80]
11	75	-	[80]
12	80	-	[]
K-Way Final Output
10 15 20 30 35 40 50 55 60 70 75 80
4. Pairwise Merge

In pairwise merging, two lists are merged at a time.

Step 1: Merge L1 and L2
L1 = 10 30 50 70
L2 = 20 40 60 80

Result:

10 20 30 40 50 60 70 80

Number of comparisons:

7
Step 2: Merge the Result with L3
First Result:
10 20 30 40 50 60 70 80

L3:
15 35 55 75

Final result:

10 15 20 30 35 40 50 55 60 70 75 80

Number of comparisons:

11
Total Pairwise Comparisons
7 + 11 = 18
5. Complexity Analysis
K-Way Merge Using Min Heap

For K sorted lists containing a total of N elements:

Time Complexity = O(N log K)

Extra Space = O(K)

For this assignment:

N = 12
K = 3

The Min Heap contains at most 3 elements at a time.

Therefore:

Maximum Heap Size = 3
Pairwise Merge

Pairwise merging repeatedly merges two sorted lists.

For K sorted lists, the general time complexity can be approximately:

O(NK)

The intermediate merged lists require additional space.

6. Comparison
Feature	K-Way Merge	Pairwise Merge
Data Structure	Min Heap	Simple arrays/lists
Maximum Heap Size	K = 3	No heap
Time Complexity	O(N log K)	Approximately O(NK)
Extra Space	O(K) heap	O(N) intermediate result
Implementation	More complex	Simple
Suitable for many files	More scalable	Less scalable
7. Advantages of K-Way Merge
Efficiently merges many sorted lists.
Uses a Min Heap to always obtain the smallest element.
Heap size depends on the number of lists, not the total number of elements.
Suitable for external sorting and merging multiple sorted files.
Time complexity is O(N log K).
8. Advantages of Pairwise Merge
Easy to understand and implement.
Does not require a heap.
Suitable when only a small number of sorted lists need to be merged.
Uses the standard two-list merge technique.
9. Conclusion

Both methods produce the same sorted output:

10 15 20 30 35 40 50 55 60 70 75 80

For the given three lists, pairwise merging requires:

18 comparisons

K-Way merging uses a Min Heap whose maximum size is:

3

The K-Way method has time complexity O(N log K), making it useful when the number of sorted files increases. Pairwise merging is simpler and can be convenient when the number of lists is small.

10. Files in This Repository
merge_comparison.c

C implementation of:

K-Way Merge using Min Heap
Pairwise Merge
Comparison counting
Heap operations
input.txt

Contains the input lists used for the experiment.

output.txt

Contains the program output.

trace_table.txt

Contains the step-by-step K-Way Min Heap trace and pairwise merge trace.

11. Final Output
10 15 20 30 35 40 50 55 60 70 75 80
