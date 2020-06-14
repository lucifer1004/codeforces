def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, x = read_ints()
    a = list(read_ints())
    s = sum(a)
    if s % x != 0:
        print(n)
    else:
        l = 0
        while l < n and a[l] % x == 0:
            l += 1
        if l == n:
            print(-1)
        else:
            r = n - 1
            while r >= 0 and a[r] % x == 0:
                r -= 1
            print(max(n - l - 1, r))
