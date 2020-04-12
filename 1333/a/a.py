t = int(input())
for case_num in range(t):
    n, m = map(int, input().split(' '))
    a = [['B' for i in range(m)] for i in range(n)]
    a[n - 1][m - 1] = 'W'
    for i in range(n):
        print(''.join(a[i]))
