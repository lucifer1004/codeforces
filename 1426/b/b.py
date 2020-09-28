def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m = read_ints()
    diag = False
    for i in range(n):
        a11, a12 = read_ints()
        a21, a22 = read_ints()
        curr = [a11, a12, a21, a22]
        if a12 == a21:
            diag = True
    print('NO' if m % 2 == 1 or not diag else 'YES')
