def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    odd = []
    even = []
    for i in range(n * 2):
        if a[i] % 2 == 0:
            even.append(i + 1)
        else:
            odd.append(i + 1)
    rem = n - 1
    while rem > 0 and len(odd) >= 2:
        rem -= 1
        print(odd[-1], odd[-2])
        odd.pop()
        odd.pop()
    while rem > 0 and len(even) >= 2:
        rem -= 1
        print(even[-1], even[-2])
        even.pop()
        even.pop()
