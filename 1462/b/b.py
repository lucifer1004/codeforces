def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    s = input()
    found = False
    for i in range(5):
        if s[:i] + s[n - 4 + i:] == '2020':
            found = True
            break
    print('YES' if found else 'NO')
