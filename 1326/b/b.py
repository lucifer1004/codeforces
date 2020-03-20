n = int(input())
a = list(map(int, input().split(' ')))
ans = [0] * n
curr = 0
for i in range(n):
    ans[i] = curr + a[i]
    curr = max(curr, ans[i])
print(' '.join(map(str, ans)))
