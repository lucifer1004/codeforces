def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


tt = read_int()
for case_num in range(tt):
    h, c, t = read_ints()
    if 2 * t <= h + c:
        print(2)
        continue
    l = 1
    r = int(1e7)

    def calc(x): return x * h + (x - 1) * c
    while l <= r:
        mid = (l + r) // 2
        temp = calc(mid)
        if temp >= t * (2 * mid - 1):
            l = mid + 1
        else:
            r = mid - 1
    a = calc(l - 1)
    b = calc(l)
    p = 2 * l - 3
    q = 2 * l - 1
    if abs(a * q - t * p * q) <= abs(b * p - t * p * q):
        print(p)
    else:
        print(q)
