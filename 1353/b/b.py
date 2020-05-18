def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    a = list(read_ints())
    b = list(read_ints())
    a.sort()
    b.sort(reverse=True)
    for i in range(k):
        if a[i] < b[i]:
            a[i] = b[i]
        else:
            break
    print(sum(a))
