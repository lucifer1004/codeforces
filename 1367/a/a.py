def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    b = input()
    l = len(b)
    a = [b[2 * i] for i in range(l // 2)]
    a.append(b[-1])
    print(''.join(a))
