def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


def cost(good, broken):
    ans = 0
    for i in range(7):
        if good[i] == '0' and broken[i] == '1':
            return -1
        if good[i] == '1' and broken[i] == '0':
            ans += 1
    return ans


s = ["{:07b}".format(i) for i in range(128)]
d = ["1110111", "0010010", "1011101", "1011011", "0111010",
     "1101011", "1101111", "1010010", "1111111", "1111011"]
f = [[-1 for i in range(8)] for j in range(128)]
g = [[] for i in range(128)]
lc = []
rc = []
for i in range(128):
    for j in range(10):
        c = cost(d[j], s[i])
        if c == -1:
            continue
        if f[i][c] == -1:
            g[i].append(c)
        f[i][c] = max(f[i][c], j)
    g[i].sort()
    lc.append(g[i][0])
    rc.append(g[i][-1])

n, k = read_ints()
nums = []
total = 0
for i in range(n):
    num = input()
    for stick in num:
        if stick == '1':
            total += 1
    nums.append(int(num, 2))

if total + k > 7 * n:
    print(-1)
else:
    lo = 0
    ls = [0]
    rs = [0]
    for i in range(n):
        ls.append(ls[-1] + lc[nums[i]])
        rs.append(rs[-1] + rc[nums[i]])
    if k < ls[n]:
        print(-1)
    else:
        ans = [-1 for i in range(n)]
        used = 0
        for i in range(n):
            rmin = ls[n] - ls[i + 1]
            rmax = rs[n] - rs[i + 1]
            u = 0
            for j in g[nums[i]]:
                if rmin <= k - used - j <= rmax:
                    if f[nums[i]][j] > ans[i]:
                        ans[i] = f[nums[i]][j]
                        u = j
            used += u
        print(int(''.join(map(str, ans))))
