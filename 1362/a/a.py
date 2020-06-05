def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b = read_ints()
    if a == b:
        print(0)
        continue
    elif a < b:
        tmp = a
        a = b
        b = tmp
    if a % b != 0:
        print(-1)
        continue
    c = a // b
    t = 0
    ok = True
    while c >= 2:
        if c % 2 == 0:
            c //= 2
            t += 1
        else:
            ok = False
            break
    print((t - 1) // 3 + 1 if ok else -1)
