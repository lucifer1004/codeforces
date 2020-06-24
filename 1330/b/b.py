def possible(a):
    ans = set()
    s = set()
    lmax = 0
    for i in range(len(a)):
        lmax = max(lmax, a[i])
        s.add(a[i])
        if lmax == i + 1 and len(s) == i + 1:
            ans.add(i + 1)
    return ans


t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    left = possible(a)
    a.reverse()
    right = possible(a)
    ans = []
    for l in left:
        if n - l in right:
            ans.append(l)
    print(len(ans))
    for l in ans:
        print(l, n - l)
