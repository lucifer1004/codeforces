from heapq import heapify, heappush, heappop
from sys import stdin


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split(' '))


t = read_int()
for case_num in range(t):
    n, m, x = read_ints()
    h = list(read_ints())
    ans = [0] * n
    towers = [(0, i) for i in range(1, m + 1)]
    blocks = [(-h[i], i) for i in range(n)]
    heapify(blocks)

    while blocks:
        block_height_neg, block_index = heappop(blocks)
        block_height = -block_height_neg
        tower_height, tower_index = heappop(towers)
        ans[block_index] = tower_index
        heappush(towers, (tower_height + block_height, tower_index))

    if max(towers)[0] - min(towers)[0] <= x:
        print('YES')
        print(' '.join(map(str, ans)))
    else:
        print('NO')
