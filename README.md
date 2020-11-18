# DAA Assignment

### Q2

```md
Suppose the job scanning through a shelf of books is to be split between k workers. 
Toavoid the need to rearrange the books or separate them into piles, we can divide the shelf into k regions and assign each region to one worker. 
What is the fairest way to divide the shelf up? 
If each book is the same length, partition the books into equal-sized regions, 100 100 100 | 100 100 100 | 100 100 100
But what if the books are not the same length? This partition would yield 100 200 300 | 400 500 600 | 700 800 900
Which part of the job would you volunteer to do? 
How can we find the fairest possiblepartition, i.e. 100 200 300 400 500 | 600 700 | 800 900

Input: A given arrangement S of non-negative numbers and an integer k.

Output: Partition S into k ranges, so as to minimize the maximum sum over all the ranges. This so-called linear partition problem arises often in parallel processing, since we seek to balance the work done across processors so as to minimize the total elapsed run time. We'll find a botched solution to this problem.

INPUT 1
9
100 200 300 400 500 600 700 800 900
3
OUTPUT 1
100 200 300 400 500
600 700 
800 900
```

### Q3

```md
Implement Greedy Fractional Knapsack for the following problems:
1.N =3, M =  20, (P1, P2, P3) = (25, 24, 15), (W1, W2, W3) =  (18, 15, 10)
2.N =7, M = 15 , (P1, P2, P3, P4, P5, P6, P7) = (10, 5, 15, 7, 6, 18, 3); (W1, W2, W3, W4, W5, W6, W7) = (2, 3, 5, 7, 1, 4, 1)

INPUT 1
3 20
25 24 15
18 15 10
OUTPUT 1
31.5

INPUT 2
7 15
10 5 15 7 6 18 3
2 3 5 7 1 4 1
OUTPUT 2
55.3333

```