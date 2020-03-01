mod = 1000000007


def fexp(x, y):
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = ans * x % mod
        x = x * x % mod
        y //= 2
    return ans


h, w = map(int, input().split(' '))
r = list(map(int, input().split(' ')))
c = list(map(int, input().split(' ')))
fixed = [[0 for i in range(w)] for i in range(h)]
ok = True
for i in range(h):
    for j in range(r[i]):
        fixed[i][j] = 1
    if r[i] < w:
        fixed[i][r[i]] = -1

for i in range(w):
    for j in range(c[i]):
        if fixed[j][i] == -1:
            ok = False
        fixed[j][i] = 1
    if c[i] < h:
        if fixed[c[i]][i] == 1:
            ok = False
        fixed[c[i]][i] = -1

if not ok:
    print(0)
else:
    count = 0
    for i in range(h):
        for j in range(w):
            if fixed[i][j] == 0:
                count += 1
    print(fexp(2, count))
