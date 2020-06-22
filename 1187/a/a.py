def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, s, t = read_ints()
    both = s + t - n
    print(max(s - both, t - both) + 1)
