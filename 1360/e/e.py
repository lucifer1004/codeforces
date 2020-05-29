def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    mat = []
    for i in range(n):
        mat.append(input())
    ok = True
    for i in range(n):
        for j in range(n):
            if mat[i][j] == '0':
                continue
            cok = j == n - 1 or i == n - 1
            if not cok:
                cok = mat[i][j + 1] == '1' or mat[i + 1][j] == '1'
            if not cok:
                ok = False
                break
        if not ok:
            break
    print('YES' if ok else 'NO')
