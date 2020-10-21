def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    x = read_int()
    i = x % 10
    n = len(str(x))
    print(10 * (i - 1) + (1 + n) * n // 2)
