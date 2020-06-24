def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


w1, h1, w2, h2 = read_ints()
print((w1 + h1 + h2) * 2 + 4)
