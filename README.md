DSA Assignment 2 – K-Way Merge vs Pairwise Merge
1. Problem Statement

The objective of this assignment is to merge three already sorted lists into a single sorted list using two different methods.

The first method is K-Way Merge using a Min Heap. The second method is Pairwise Merge.

The two methods are compared based on the number of comparisons, heap size, time complexity, extra space, and their suitability when the number of sorted files increases.

2. Input Lists

The three sorted lists used in this assignment are:

L1: 10, 30, 50, 70

L2: 20, 40, 60, 80

L3: 15, 35, 55, 75

There are a total of 12 elements, and the number of sorted lists is 3.

3. K-Way Merge Using Min Heap

In K-Way Merge, the smallest element from each sorted list is first inserted into a Min Heap.

The initial elements are 10 from L1, 20 from L2, and 15 from L3. Therefore, the initial heap contains 10, 20, and 15.

The Min Heap always keeps the smallest element at the top. The smallest element is removed from the heap, added to the final output, and then the next element from the same list is inserted into the heap.

For example, when 10 is removed from L1, the next element 30 from L1 is inserted into the heap. This process continues until all elements from the three lists have been processed.

The final sorted output obtained using K-Way Merge is:

10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80

K-Way Merge Process

The heap processing takes place in the following order:

Remove 10 and insert 30.
Remove 15 and insert 35.
Remove 20 and insert 40.
Remove 30 and insert 50.
Remove 35 and insert 55.
Remove 40 and insert 60.
Remove 50 and insert 70.
Remove 55 and insert 75.
Remove 60 and insert 80.
Remove 70.
Remove 75.
Remove 80.

After the last element is removed, the heap becomes empty.

The maximum heap size is 3, because there are three sorted lists.

4. Pairwise Merge

In Pairwise Merge, two sorted lists are merged first, and the resulting list is then merged with the remaining list.

Step 1: Merge L1 and L2

The first list contains 10, 30, 50, and 70. The second list contains 20, 40, 60, and 80.

After merging L1 and L2, the result is:

10, 20, 30, 40, 50, 60, 70, 80

The number of comparisons in this step is 7.

Step 2: Merge the Result with L3

The result obtained from the first step is merged with L3, which contains 15, 35, 55, and 75.

The final result is:

10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80

The number of comparisons in this step is 11.

Therefore, the total number of Pairwise Merge comparisons is:

7 + 11 = 18 comparisons

5. Complexity Analysis

For K-Way Merge using a Min Heap, the time complexity is O(N log K), where N is the total number of elements and K is the number of sorted lists.

The extra space required for the Min Heap is O(K).

For the given problem, N is 12 and K is 3. Therefore, the maximum heap size is 3.

For Pairwise Merge, the lists are merged one after another. The general time complexity can be approximately O(NK), and intermediate merged lists require additional space.

6. Comparison of the Two Methods
Feature	K-Way Merge	Pairwise Merge
Data Structure	Min Heap	Arrays/Lists
Maximum Heap Size	3	No heap
Time Complexity	O(N log K)	Approximately O(NK)
Extra Space	O(K)	O(N) intermediate space
Implementation	More complex	Simple
Multiple Files	Suitable for many files	More suitable for fewer files
7. Advantages of K-Way Merge

K-Way Merge is useful when several sorted lists or files need to be merged. The Min Heap allows the smallest available element to be selected efficiently.

Its time complexity is O(N log K), and the heap contains only one element from each list at a time.

8. Advantages of Pairwise Merge

Pairwise Merge is simple to understand and easy to implement. It does not require a heap and works well when only a small number of sorted lists need to be merged.

9. Conclusion

Both methods produce the same final sorted output:

10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80

For the given input, Pairwise Merge requires 18 comparisons.

K-Way Merge uses a Min Heap with a maximum size of 3. Its time complexity is O(N log K), which makes the method useful for merging multiple sorted files.

Pairwise Merge is simpler, while K-Way Merge provides a more scalable approach when the number of sorted lists increases.

10. Files in the Repository

The repository contains the following files:

merge_comparison.c – Contains the C implementation of K-Way Merge and Pairwise Merge.
input.txt – Contains the input lists.
output.txt – Contains the program output.
trace_table.txt – Contains the step-by-step merge trace.
README.md – Contains the explanation, analysis, and comparison of both methods.
