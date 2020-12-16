def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    n = read_int()
    if n > 45:
        print(-1)
        continue
    a = []
    while n > 0:
        for i in range(min(n, 9), 0, -1):
            if i not in a:
                a.append(i)
                n -= i
                break
    print(''.join(map(str, a[::-1])))
