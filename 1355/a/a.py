def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, k = read_ints()
    i = 1
    while i < k:
        s = str(a)
        lo = int(min(s))
        hi = int(max(s))
        if lo == 0:
            break
        a += lo * hi
        i += 1
    print(a)
