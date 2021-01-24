def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    n = read_int()
    b = input()
    a = []
    for i, c in enumerate(b):
        if i == 0:
            a.append('1')
        else:
            last = int(b[i - 1]) + int(a[i - 1])
            if last == 2:
                a.append('1' if c == '0' else '0')
            elif last == 1:
                a.append('1' if c == '1' else '0')
            else:
                a.append('1')
    print(''.join(a))
