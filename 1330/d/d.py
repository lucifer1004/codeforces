t = int(input())
maxd = 32
for case_num in range(t):
    d, m = map(int, input().split(' '))
    cnt = [0] * maxd
    num = 2
    i = 1
    while num - 1 <= d:
        cnt[i] = num // 2
        num *= 2
        i += 1
    cnt[i] = d - num // 2 + 1
    ans = 1
    for l in range(1, maxd):
        ans = ans * (cnt[l] + 1) % m
    ans = (ans - 1 + m) % m
    print(ans)
