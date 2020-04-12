t = int(input())
for case_num in range(t):
    n, l, r = map(int, input().split(' '))
    if l == n * (n-1) + 1:
        print(1)
        continue
    total = 0
    unvisited = n - 1
    while total < l:
        total += unvisited * 2
        unvisited -= 1
    unvisited += 1
    total -= unvisited * 2
    current = n - unvisited
    nxt = current + 1
    ans = []
    while total < r:
        total += 1
        now = current if total % 2 == 1 else nxt
        if now == nxt:
            nxt += 1
            if nxt > n:
                current += 1
                nxt = current + 1
                if current == n:
                    current = 1
        if total >= l:
            ans.append(now)
    print(' '.join(map(str, ans)))
