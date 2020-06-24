n = int(input())
a = list(map(int, input().split(' ')))
a.sort()
mark = [False for i in range(n)]
ans = 0
for i in range(n):
    if not mark[i]:
        mark[i] = True
        ans += 1
        for j in range(i + 1, n):
            if a[j] % a[i] == 0:
                mark[j] = True
print(ans)
