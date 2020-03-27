def gcd(x, y):
    return x if y == 0 else gcd(y, x % y)


n = int(input())
a = list(map(int, input().split(' ')))
g = 0
for i in a:
    g = gcd(g, i)
ans = 0
i = 1
while i * i <= g:
    if g % i == 0:
        ans += 1
        if i != g // i:
            ans += 1
    i += 1
print(ans)
