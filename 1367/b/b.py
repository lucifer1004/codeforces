def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    o2e = 0
    e2o = 0
    for i in range(n):
        if i % 2 == 0 and a[i] % 2 != 0:
            o2e += 1
        if i % 2 != 0 and a[i] % 2 == 0:
            e2o += 1
    print(-1 if o2e != e2o else o2e)
