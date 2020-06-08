def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    b = list(read_ints())
    tot = sum(b)
    c = list(a)
    c.sort()
    if c == a:
        print('Yes')
    else:
        print('No' if tot == 0 or tot == n else 'Yes')
