t = int(input())
for case_num in range(t):
    n = int(input())
    p = list(map(int, input().split(' ')))
    x, a = map(int, input().split(' '))
    y, b = map(int, input().split(' '))
    k = int(input())
    p.sort()
    p.reverse()
    sum = [0]
    for i in range(n):
        sum.append(sum[-1] + p[i])
    if x < y:
        x, y = y, x
        a, b = b, a
    nab = 0
    na = 0
    nb = 0
    ans = -1
    for i in range(1, n + 1):
        if i % a != 0 and i % b != 0:
            continue
        if i % a == 0 and i % b == 0:
            nab += 1
        if i % a == 0 and i % b != 0:
            na += 1
        if i % a != 0 and i % b == 0:
            nb += 1
        current = (sum[nab] * (x + y) + (sum[nab + na] - sum[nab])
                   * x + (sum[nab + na + nb] - sum[nab + na]) * y) // 100
        if current >= k:
            ans = i
            break
    print(ans)
