def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a = list(read_ints())
    b = list(read_ints())
    ok = False
    for i in range(2):
        for j in range(2):
            if a[i] != b[j]:
                continue
            if a[1 - i] + b[1 - j] == a[i]:
                ok = True
    print('Yes' if ok else 'No')
