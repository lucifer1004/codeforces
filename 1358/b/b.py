from collections import Counter


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    cnt = Counter(a)
    tot = 1
    ans = 1
    for i in range(1, n + 1):
        if not i in cnt:
            continue
        tot += cnt[i]
        if tot - 1 >= i:
            ans = tot
    print(ans)
