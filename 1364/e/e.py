from random import randint
from functools import lru_cache


@lru_cache(None)
def query(i, j):
    print(f'? {i} {j}')
    return int(input())


n = int(input())
val = query(1, 2)
a = 1
b = 2
for c in range(3, n + 1):
    new = query(b, c)
    if new < val:
        a = c
        val = new
    elif new == val:
        b = c
        val = query(a, b)
z = 0
while True:
    c = randint(1, n)
    if c == a or c == b:
        continue
    av = query(a, c)
    bv = query(b, c)
    if av < bv:
        z = a
        break
    elif av > bv:
        z = b
        break
ans = [0 for i in range(n)]
for i in range(1, n + 1):
    if i == z:
        continue
    ans[i - 1] = query(z, i)
print('! ' + ' '.join(map(str, ans)))
