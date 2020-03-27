from collections import Counter
t = int(input())
for case_num in range(t):
    n = int(input())
    cnt = Counter(map(int, input().split(' ')))
    a = list(cnt)
    a.sort()
    l = 0
    r = len(a) - 1
    area = a[l] * a[r]
    ok = True
    while l <= r:
        if a[l] * a[r] != area or cnt[a[l]] != cnt[a[r]] or cnt[a[l]] % 2 == 1 or (l == r and cnt[a[l]] % 4 != 0):
            ok = False
            break
        l += 1
        r -= 1
    print('YES' if ok else 'NO')
