f = [[1, i] for i in range(20001)]
for i in range(2, 20001):
    j = 2
    while j * j <= i:
        if i % j == 0:
            f[i].append(j)
            f[i].append(i // j)
        j += 1
    f[i] = list(set(f[i]))
    f[i].sort()


t = int(input())
for case_num in range(t):
    a, b, c = map(int, input().split(' '))
    best = 60000
    global ans
    ans = []
    for nc in range(1, 20001):
        l = len(f[nc])
        cost = abs(nc - c)
        if cost >= best:
            continue
        for nb in f[nc]:
            for na in f[nb]:
                new_cost = cost + abs(na - a) + abs(nb - b)
                if new_cost < best:
                    best = new_cost
                    ans = [na, nb, nc]
    print(best)
    print(' '.join(map(str, ans)))
