from math import ceil

n, w = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
indexed = [(a[i], i) for i in range(n)]
indexed.sort()
b = [0] * n
for i in range(n):
    volume, idx = indexed[i]
    b[idx] = ceil(volume / 2)
    w -= b[idx]
if w > 0:
    for i in range(n):
        volume, idx = indexed[n - i - 1]
        extra = min(w, volume - b[idx])
        b[idx] += extra
        w -= extra
        if w == 0:
            break
print(-1 if w < 0 else ' '.join(map(str, b)))
