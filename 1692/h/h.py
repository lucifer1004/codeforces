from sys import stdin
from collections import defaultdict, Counter
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    x = list(read_ints())
    l = 1
    r = 1
    ans = 1
    choice = x[0]

    # Solution 1: solve for each number separately
    # p = defaultdict(list)
    # for i, xi in enumerate(x):
    #     p[xi].append(i)

    # for num in p:
    #     mini = 0
    #     minv = 1000000
    #     for i, vi in enumerate(p[num]):
    #         now = 2 * i - vi
    #         if i > 0:
    #             cur = now - minv + 1
    #             if cur > ans:
    #                 ans = cur
    #                 choice = num
    #                 l = p[num][mini] + 1
    #                 r = vi + 1
    #         if now < minv:
    #             minv = now
    #             mini = i

    # Solution 2: solve all numbers together
    c = Counter()
    d = defaultdict(lambda: 1000000)
    e = defaultdict(int)

    ans = 1
    l = 1
    r = 1
    choice = x[0]

    for i, num in enumerate(x):
        c[num] += 1
        diff = c[num] - (i + 1 - c[num])
        if diff - d[num] + 1 > ans:
            ans = diff - d[num] + 1
            l = e[num] + 1
            r = i + 1
            choice = x[i]
        if diff < d[num]:
            d[num] = diff
            e[num] = i

    print(choice, l, r)
