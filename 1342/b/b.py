def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a = input()
    n = len(a)
    one = 0
    for c in a:
        if c == '1':
            one += 1
    if one == 0 or one == n:
        print(a)
    else:
        print(''.join(['01' for i in range(n)]))
