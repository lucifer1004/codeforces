def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b = read_ints()
    print(min((a + b) // 3, min(a, b)))
