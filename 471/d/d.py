n, w = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
if w > n:
    print(0)
elif w == 1:
    print(n)
else:
    da = [a[i + 1] - a[i] for i in range(n - 1)]
    db = [b[i + 1] - b[i] for i in range(w - 1)]
    ans = 0
    t = db + [-10000000000] + da
    pi = [0 for i in range(len(t))]
    for i in range(1, len(t)):
        j = pi[i - 1]
        while j != 0 and t[i] != t[j]:
            j = pi[j - 1]
        pi[i] = j + 1 if t[i] == t[j] else 0
        if pi[i] == w - 1:
            ans += 1
    print(ans)
