t = int(input())
for case_num in range(t):
    b, p, f = map(int, input().split(' '))
    h, c = map(int, input().split(' '))
    if h > c:
        tmp = p
        p = f
        f = tmp
        tmp = h
        h = c
        c = tmp
    ans = 0
    nc = min(f, b // 2)
    ans += nc * c
    b -= nc * 2
    nh = min(p, b // 2)
    ans += nh * h
    print(ans)
