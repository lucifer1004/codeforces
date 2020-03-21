# Educational Codeforces Round 21

- [x] A
- [x] B
- [x] C
- [x] D
- [x] E
- [ ] F
- [x] G

## Problem E - Selling Souvenirs

Typical knapsack solution will get TLE. Since the weight can only be 1, 2 or 3, there is a greedy solution according to the unit value of all items.

We sort all the items in the descending order according to unit value, and then count them one by one. During the process, we maintain three max-heaps for items not added yet, and three min-heaps for items added.

If the rest space equals 0, then we have found the best solution.

If the rest space equals 1, we have the following choices:
- Add 1
- Remove 1 and add 2
- Remove 2 and add 3
- Remove two 1s and add 3
- Remove 3 and add two 2s

If the rest space equals 2, we have the following choices:
- Add two 1s
- Add 2
- Remove 1 and add 3
- Remove 2 and add 1 and 3

Other choices will denifitely reduce the total value.

## Problem G - Anthem of Berland

The restriction on $|s|\cdot|t|$ is an apparent hint that we should use 2-D Dynamic Programming. The transfer is quite natural, except for the case $j=|t|$. To solve this issue, we introduce the prefix function.