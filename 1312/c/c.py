t = int(input())
for case_num in range(t):
    n, k = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    d = dict()
    for i in a:
        num = i
        level = 0
        while num > 0:
            if not level in d:
                d[level] = 0
            d[level] += num % k
            num //= k
            level += 1
    ok = True
    for i in d:
        if d[i] > 1:
            ok = False
            break
    print("YES" if ok else "NO")
