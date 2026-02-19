*This project was created as part of the 42 curriculum by lde-frei.*

PUSH_SWAP

# DESCRIPTION

The push_swap project aims to develop a C program capable of sorting a list of integers
using a strict set of operations and two stacks. The main goal is to work with logic,
algorithms, and move optimization.

We start with a sequence of integers given as arguments, store them in stack A,
and use stack B to help sort the numbers in ascending order in stack A.

Allowed Operations:

SWAP
	sa → swap the first two elements of stack A.
	sb → swap the first two elements of stack B.
	ss → perform sa and sb at the same time.

PUSH
	pa → move the top element of stack B to stack A.
	pb → move the top element of stack A to stack B.

ROTATE
	ra → shift up all elements of stack A by 1 (first element becomes the last).
	rb → shift up all elements of stack B by 1.
	rr → perform ra and rb at the same time.

REVERSE ROTATE
	rra → shift down all elements of stack A by 1 (last element becomes the first).
	rrb → shift down all elements of stack B by 1.
	rrr → perform rra and rrb at the same time.

# INSTRUCTIONS

To run the push_swap program, first give execution permission using chmod.
Then run it in your terminal with a sequence of integers:
```
./push_swap 10 9 8 7 6 5 4 3 2 1
```
Or:
```
./push_swap $(shuf -i 1-500 -n 500) | wc -l
```

The second command generates 500 random numbers as arguments for push_swap.
Then, using wc -l, we count how many operations were needed to sort the 500 integers.

! The input must contain only integers, without duplicates or any other characters.

# ALGORITHM

Longest Increasing Subsequence (LIS).
The objective of this algorithm is to find the longest increasing subsequence.

Example:

A  = [1, 10, 3, 0, 6, 20, 7, 30, 2, 40]
LIS = [1, 10, 20, 30, 40]

After identifying the LIS, we push to stack B every node that does not belong to the LIS.
To efficiently move elements back to stack A, we calculate the target position, which is
the smallest number greater than the current node in stack B.
We then:
Find the cheapest node (in terms of move cost) to place on top.
Push it back to stack A.
At this point, the stack is arranged in a circular pattern.
With a final rotation, we place the smallest element at the top, fully sorting the stack.

# RESOURCES

AI was used to:
Clarify algorithm concepts.
Explore implementation approaches.
Identify potential memory leaks.
