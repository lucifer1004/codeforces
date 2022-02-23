from sys import stdin
from collections import Counter
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    cnt = Counter(a)
    valid = True

    for value in cnt.values():
        if value % 2 == 1:
            valid = False
            break

    # Operations do not change parities
    if not valid:
        print(-1)
        continue

    l = 0
    r = 1
    while a[r] != a[0]:
        r += 1

    operations = []
    groups = []
    base = 0

    # actual = list(a)

    while l < n:
        length = r - l
        for i in range(1, length):
            operations.append((base + length + i, a[l + i]))
            # actual = actual[:base + length + i] + \
            #     [a[l + i]] * 2 + actual[base + length + i:]
        base += 2 * length
        groups.append(length * 2)
        a[l+2:r+1] = a[l+1:r][::-1]
        l += 2
        r = l + 1
        while r < n and a[r] != a[l]:
            r += 1

    print(len(operations))
    for p, c in operations:
        print(p, c)
    print(len(groups))
    print(' '.join(map(str, groups)))

    # now = 0
    # assert(len(actual) == sum(groups))
    # for g in groups:
    #     part = actual[now:now+g]
    #     assert(part[:g//2] == part[g//2:])
    #     now += g
