def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


d = [(1, 1), (0, 1), (-1, 0), (-1, -1), (0, -1), (1, 0)]
t = read_int()
for case_num in range(t):
    x, y = read_ints()
    c = list(read_ints())
    ans = -1
    for i in range(6):
        dx = d[i][0]
        dy = d[i][1]
        if dx != 0 and x // dx >= 0:
            t = x // dx
            cost = t * c[i]
            y1 = d[i][1] * t
            for j in range(6):
                if j == i or d[j][0] != 0:
                    continue
                t1 = (y - y1) // d[j][1]
                if t1 >= 0:
                    nc = cost + t1 * c[j]
                    if ans == -1 or ans > nc:
                        ans = nc

        if dy != 0 and y // dy >= 0:
            t = y // dy
            cost = t * c[i]
            x1 = d[i][0] * t
            for j in range(6):
                if j == i or d[j][1] != 0:
                    continue
                t1 = (x - x1) // d[j][0]
                if t1 >= 0:
                    nc = cost + t1 * c[j]
                    if ans == -1 or ans > nc:
                        ans = nc
    print(ans)
