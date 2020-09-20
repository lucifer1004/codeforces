def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    n = read_int()
    s = input()
    a = 0
    b = 0
    for (i, c) in enumerate(s):
        if i % 2 == 0 and int(c) % 2 == 1:
            a += 1
        if i % 2 == 1 and int(c) % 2 == 0:
            b += 1
    if n % 2 == 1:
        print(1 if a > 0 else 2)
    else:
        print(2 if b > 0 else 1)
