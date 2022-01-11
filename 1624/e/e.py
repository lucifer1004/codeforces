from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    input()
    n, m = read_ints()
    phones = [input() for _ in range(n + 1)]

    d = dict()
    for k, phone in enumerate(phones):
        if k == n:
            break

        for i in range(m - 1):
            d[phone[i: i + 2]] = (i, k)
        for i in range(m - 2):
            d[phone[i: i + 3]] = (i, k)

    pre = [-1] * (m + 1)
    pre[0] = 0
    target = phones[n]
    for i in range(m - 1):
        if pre[i] == -1:
            continue
        two = target[i: i + 2]
        if two in d:
            pre[i + 2] = i
        if i + 3 <= m:
            three = target[i: i + 3]
            if three in d:
                pre[i + 3] = i

    if pre[m] == -1:
        print(-1)
    else:
        ans = []
        now = m
        while now != 0:
            delta = now - pre[now]
            seg = target[pre[now]: now]
            l, k = d[seg]
            ans.append((l + 1, l + delta, k + 1))
            now = pre[now]
        print(len(ans))
        for l, r, k in ans[::-1]:
            print(l, r, k)
