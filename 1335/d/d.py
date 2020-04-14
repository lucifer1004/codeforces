t = int(input())
r = [i for i in range(9)]
c = [0, 3, 6, 1, 4, 7, 2, 5, 8]
for case_num in range(t):
    a = []
    for i in range(9):
        row = input()
        tmp = []
        for char in row:
            tmp.append(int(char))
        a.append(tmp)
    for i in range(9):
        m = 1 + a[r[i]][c[i]]
        if m > 9:
            m = 1
        a[r[i]][c[i]] = m
    for i in range(9):
        print(''.join(map(str, a[i])))
