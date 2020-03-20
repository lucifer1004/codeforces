n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
sum = (2 * n - k + 1) * k // 2
lo = n - k + 1
cnt = 0
b = []
for i in a:
    if i >= lo:
        b.append(cnt)
        cnt = 0
    else:
        cnt += 1
b.append(cnt)
ans = 1
mod = 998244353
for i in range(1, len(b) - 1):
    ans = ans * (b[i] + 1) % mod
print(sum, ans)
