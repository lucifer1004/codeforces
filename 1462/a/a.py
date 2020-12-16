def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    l = 0
    r = n - 1
    ans = []
    for i in range(n):
        if i % 2 == 0:
            ans.append(a[l])
            l += 1
        else:
            ans.append(a[r])
            r -= 1
    print(' '.join(map(str, ans)))
