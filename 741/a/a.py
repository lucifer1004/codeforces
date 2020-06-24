def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


def gcd(x, y):
    return x if y == 0 else gcd(y, x % y)


n = read_int()
a = list(read_ints())
vis = [False for i in range(n)]
loop = 0
ok = True
for i in range(n):
    if vis[i]:
        continue
    current = i
    length = 0
    while not vis[current]:
        vis[current] = True
        current = a[current] - 1
        length += 1
    if current != i:
        ok = False
        print(-1)
        break
    if length % 2 == 0:
        length //= 2
    if loop == 0:
        loop = length
    else:
        loop = loop * length // gcd(loop, length)
if ok:
    print(loop)
