t = int(input())
for case_num in range(t):
    n, x = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    s = set(a)
    ans = 1
    while x >= 0:
        if not ans in s:
            if x == 0:
                ans -= 1
                break
            x -= 1
        ans += 1
    print(ans)
