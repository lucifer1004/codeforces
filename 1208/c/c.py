n = int(input())
basic = [[8, 9, 1, 13], [3, 12, 7, 5], [0, 2, 4, 11], [6, 10, 15, 14]]
ans = [[0 for i in range(n)] for i in range(n)]
m = n // 4
for i in range(n):
    for j in range(n):
        ans[i][j] = basic[i % 4][j % 4] + 16 * (i // 4 * m + j // 4)
for i in range(n):
    print(' '.join(map(str, ans[i])))
