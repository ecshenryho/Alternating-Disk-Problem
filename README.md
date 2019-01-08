# Alternating-Disk-Problem

You have a row of 2n disks of two colors, n dark and n light. They alternate: dark, light, dark, light, and so on. You want to get all the dark disks to the right-hand end, and all the light disks to the left-hand end. The only moves you are allowed to make are those that interchange the positions of two neighboring disks. Design an algorithm for solving this puzzle and determine the number of moves it takes.



#The alternating disks problem is: 

Input: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark
Output: a list of 2n disks, the first n disks are light, the next n disks are dark, and an integer m representing the number of swaps to move the dark ones after the light ones

There are two algorithms, presented below, that solve this problem in in O(n2)time. You need to translate these descriptions into clear pseudocode.

The first algorithm starts with the leftmost disk and proceeds to the right until it reaches the rightmost disk: compares every two adjacent disks and swaps them only if necessary. Now we have one lighter disk at the left-hand end and the darker disk at the right-hand end. Once it reaches the right-hand end, it goes back to the leftmost disk and proceeds to the right, doing the swaps as necessary. It repeats n times.

The second algorithm proceeds like a lawnmower: starts with the leftmost disk and proceeds to the right until it reaches the rightmost disk: compares every two adjacent disks and swaps them only if necessary. Now we have one lighter disk at the left-hand end and the darker disk at the right-hand end. Once it reaches the right-hand end, it starts with the rightmost disk, compares every two adjacent disks and proceeds to the left until it reaches the leftmost disk, doing the swaps only if necessary. The lawnmower movement is repeated ⌈n/2⌉ times.

For each algorithm, some improvement can be obtained by not going all the way to the left or to the right, since some disks at the ends are already in the correct position.

@The left-to-right algorithm
It starts with the leftmost disk and proceeds to the right, doing the swaps as necessary. Now we have one lighter disk at the left-hand end and the darker disk at the right-hand end. Once it reaches the right-hand end, it goes back to the leftmost disk and proceeds to the right, doing the swaps as necessary. It repeats until there are no more disks to move.



#The lawnmower algorithm
It starts with the leftmost disk and proceeds to the right, doing the swaps as necessary. Now we have one lighter disk at the left-hand end and the darker disk at the right-hand end. Once it reaches the right-hand end, it starts with the disk before the rightmost disk and proceeds to the left, doing the swaps as necessary, until it reaches the disk before the left-hand end. It repeats until there are no more disks to move.


Algorithm Design
Your first task is to design an algorithm for each of the two problems. Write clear pseudocode for each algorithm. This is not intended to be difficult; the algorithms I have in mind are all relatively simple, involving only familiar string operations and loops (nested loops in the case of oreos and substrings). Do not worry about making these algorithms exceptionally fast; the purpose of this experiment is to see whether observed timings correspond to big-O trends, not to design impressive algorithms.


