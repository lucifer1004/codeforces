t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.sort()
    ans = []
    l = 0
    r = n - 1
    while l <= r:
        ans.append(a[l])
        if l < r:
            ans.append(a[r])
        l += 1
        r -= 1
    ans.reverse()
    print(' '.join(map(str, ans)))
