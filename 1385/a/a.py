def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b, c = read_ints()
    if a == b:
        if a < c:
            print('NO')
        else:
            print('YES')
            print(a, c, c)
    elif a == c:
        if a < b:
            print('NO')
        else:
            print('YES')
            print(b, a, b)
    elif b == c:
        if b < a:
            print('NO')
        else:
            print('YES')
            print(a, a, b)
    else:
        print('NO')
