w, h, n = map(int, input().split(' '))
hblock = [[False for i in range(w)] for i in range(h)]
vblock = [[False for i in range(w)] for i in range(h)]

for i in range(n):
    x1, y1, x2, y2 = map(int, input().split(' '))
    if x1 == x2:
        for j in range(y1, y2):
            hblock[j][x1-1] = True
    else:
        for j in range(x1, x2):
            vblock[y1-1][j] = True

areas = []
vis = [[False for i in range(w)] for i in range(h)]
for i in range(h):
    for j in range(w):
        if vis[i][j]:
            continue
        width = j
        while width < w and not hblock[i][width]:
            width += 1
        height = i
        while height < h and not vblock[height][j]:
            height += 1
        width = min(w - 1, width) - j + 1
        height = min(h - 1, height) - i + 1
        areas.append(width * height)
        for p in range(height):
            for q in range(width):
                vis[i + p][j + q] = True
areas.sort()
print(' '.join(map(str, areas)))
