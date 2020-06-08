def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m = read_ints()
    a = []
    for i in range(n):
        a.append(list(read_ints()))
    row = set([i for i in range(n)])
    col = set([i for i in range(m)])
    for i in range(n):
        for j in range(m):
            if a[i][j] == 1:
                if i in row:
                    row.remove(i)
                if j in col:
                    col.remove(j)
    lo = min(len(row), len(col))
    print("Ashish" if lo % 2 == 1 else "Vivek")
