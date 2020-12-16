def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    part = 0
    s = sum(a)
    found = False
    for i in range(n - 1):
        part += a[i]
        if s % part != 0:
            continue
        valid = True
        curr = 0
        for j in range(i + 1, n):
            if curr + a[j] > part:
                valid = False
                break
            elif curr + a[j] == part:
                curr = 0
            else:
                curr += a[j]
        if valid:
            print(n - s // part)
            found = True
            break
    if not found:
        print(n - 1)
