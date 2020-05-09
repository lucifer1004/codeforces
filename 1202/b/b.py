from collections import deque

s = input()
dist = dict()
for x in range(10):
    for y in range(10):
        for a in range(10):
            for b in range(a, 10):
                vis = [-1 for i in range(10)]
                vis[x] = 0
                q = deque()
                q.append(x)
                while len(q) > 0:
                    f = q.popleft()
                    if f == y and vis[y] != 0:
                        dist[((x, y), (a, b))] = vis[y]
                        break
                    anxt = (f + a) % 10
                    if vis[anxt] == -1 or (vis[anxt] == 0 and anxt == y):
                        q.append(anxt)
                        vis[anxt] = vis[f] + 1
                    bnxt = (f + b) % 10
                    if vis[bnxt] == -1 or (vis[bnxt] == 0 and bnxt == y):
                        q.append(bnxt)
                        vis[bnxt] = vis[f] + 1

ans = [[0 for i in range(10)] for j in range(10)]
cnt = dict()
for i in range(len(s) - 1):
    x = int(s[i])
    y = int(s[i + 1])
    if not (x, y) in cnt:
        cnt[(x, y)] = 0
    cnt[(x, y)] += 1

for a in range(10):
    for b in range(a, 10):
        for ckey in cnt:
            key = (ckey, (a, b))
            if not key in dist:
                ans[a][b] = -1
                break
            else:
                ans[a][b] += (dist[key] - 1) * cnt[ckey]
        ans[b][a] = ans[a][b]
for i in range(10):
    print(' '.join(map(str, ans[i])))
