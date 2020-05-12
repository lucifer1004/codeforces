def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b, c = read_ints()
    if b == 0:
        if a > 0:
            print('0' * (a + 1))
        else:
            print('1' * (c + 1))
    else:
        mid = ('01' * b)[:b+1]
        left = '0' * a
        if b % 2 == 1:
            right = '1' * c
            print(left + mid + right)
        else:
            print(left + mid[0] + '1' * c + mid[1:])
