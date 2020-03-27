t = int(input())
for case_num in range(t):
    n, k = map(int, input().split(' '))
    l = 1
    r = n - 1
    while l <= r:
        mid = (l + r) // 2
        num = mid * (mid + 1) // 2
        if k <= num:
            r = mid - 1
        else:
            l = mid + 1
    num = l * (l + 1) // 2
    ans = ['a' for i in range(n)]
    ans[-l-1] = 'b'
    rest = l - num + k
    ans[-rest] = 'b'
    print(''.join(ans))
