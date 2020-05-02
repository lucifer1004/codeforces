from collections import Counter

def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    a = list(read_ints())
    cnt = Counter(a)
    distinct = len(cnt)
    if distinct > k:
        print(-1)
    else:
        print(n * k)
        s = set(cnt)
        for i in range(1, n + 1):
            if len(s) < k and not i in s:
                s.add(i)
        ans = list(s) * n
        print(' '.join(map(str, ans)))