from math import sqrt


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    mid = int(sqrt(n))
    ans = n
    for i in range(max(1, mid - 5), min(n, mid + 5) + 1):
        rem = n % i
        tot = i - 1 + n // i - 1
        if rem > 0:
            tot += 1
        ans = min(ans, tot)
    print(ans)
