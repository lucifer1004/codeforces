n, m = map(int, input().split(' '))
limit = 0
for i in range(3, n + 1):
    limit += (i - 1) // 2
if m > limit:
    print(-1)
else:
    a = [i for i in range(1, n + 1)]
    count = limit
    i = n
    while count > m:
        curr = (i - 1) // 2
        to_del = min(curr, count - m)
        if to_del == curr:
            a[i - 1] = 1000000000 - (n - i) * 10000
        else:
            a[i - 1] = a[i - 2] + a[i - 1 - 2 * (curr - to_del)]
        count -= to_del
        i -= 1
    print(' '.join(map(str, a)))
