def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m, x, y = read_ints()
    a = []
    cost = 0
    for i in range(n):
        row = input() + '*'
        white = 0
        for c in row:
            if c == '*':
                if white > 0:
                    cost += min(white * x, white // 2 * y + white % 2 * x)
                white = 0
            else:
                white += 1
    print(cost)
