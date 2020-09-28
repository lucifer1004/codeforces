def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, x = read_ints() 
    if n <= 2:
        print(1)
    else:
        n -= 2
        print((n - 1) // x + 2)
