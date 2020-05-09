def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
INF = int(1e7)
for case_num in range(t):
    s = input()
    x = 0
    y = 0
    xlist = [0]
    ylist = [0]
    for c in s:
        if c == 'W':
            y += 1
        elif c == 'S':
            y -= 1
        elif c == 'A':
            x -= 1
        else:
            x += 1
        xlist.append(x)
        ylist.append(y)
    n = len(s)
    l = [0]
    r = [0]
    u = [0]
    d = [0]
    for i in range(1, n + 1):
        l.append(min(l[-1], xlist[i]))
        r.append(max(r[-1], xlist[i]))
        u.append(max(u[-1], ylist[i]))
        d.append(min(d[-1], ylist[i]))
    lr = [xlist[n]]
    rr = [xlist[n]]
    ur = [ylist[n]]
    dr = [ylist[n]]
    for i in range(1, n + 1):
        lr.append(min(lr[-1], xlist[n - i]))
        rr.append(max(rr[-1], xlist[n - i]))
        ur.append(max(ur[-1], ylist[n - i]))
        dr.append(min(dr[-1], ylist[n - i]))
    ans = INF * INF
    coeff = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    for k in range(4):
        for i in range(n):
            nl = min(l[i], lr[n - i] + coeff[k][0])
            nr = max(r[i], rr[n - i] + coeff[k][0])
            nu = max(u[i], ur[n - i] + coeff[k][1])
            nd = min(d[i], dr[n - i] + coeff[k][1])
            area = (nr - nl + 1) * (nu - nd + 1)
            ans = min(ans, area)
    print(ans)
