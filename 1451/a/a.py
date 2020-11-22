def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    n = read_int()
    if n == 1:
        print(0)
    elif n == 2:
        print(1)
    elif n % 2 == 0 or n == 3:
        print(2)
    else:
        print(3)
