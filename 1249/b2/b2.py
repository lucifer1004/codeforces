t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    vis = [False for i in range(n + 1)]
    day = [0 for i in range(n + 1)]
    for i in range(1, n + 1):
        if vis[i]:
            continue
        vis[i] = True
        cnt = 1
        path = set()
        path.add(i)
        curr = a[i - 1]
        while curr != i:
            vis[curr] = True
            path.add(curr)
            curr = a[curr - 1]
            cnt += 1
        for step in path:
            day[step] = cnt
    print(' '.join(map(str, day[1:])))
