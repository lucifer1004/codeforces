def exgcd(a, b):
    if b == 0:
        return (a, 1, 0)
    [t, x, y] = exgcd(b, a % b)
    x0 = x
    y0 = y
    x = y0
    y = x0 - (a // b) * y0
    return [t, x, y]


[n, p, w, d] = map(int, input().split(' '))
[g, x, y] = exgcd(w, d)
if p % g != 0:
    print(-1)
else:
    fold = p // g
    da = d // g
    db = w // g
    nx = x * fold
    ny = y * fold
    t = int(abs(ny) // db)
    if (ny > 0):
        ny -= t * db
        nx += t * da
    else:
        ny += t * db
        nx -= t * da
        if ny < 0:
            ny += db
            nx -= da
    nz = n - nx - ny
    if nx >= 0 and ny >= 0 and nz >= 0:
        print(nx, ny, nz)
    else:
        print(-1)
