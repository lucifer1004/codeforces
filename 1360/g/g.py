def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m, a, b = read_ints()
    if n * a != m * b:
        print('NO')
    else:
        print('YES')
        ans = [[0 for i in range(m)] for j in range(n)]
        row = 0
        col = 0
        t = 0
        while True:
            ans[row][col] = 1
            t += 1
            if t == n * a:
                break
            col = (col + 1) % m
            row = (row + 1) % n
            while ans[row][col] == 1:
                col = (col + 1) % m
        for i in range(n):
            print(''.join(map(str, ans[i])))
