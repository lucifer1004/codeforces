import bisect
import collections

t = int(input())
for case_num in range(t):
    n, k = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    x = [a[i] + a[n - 1 - i] for i in range(n // 2)]
    x = collections.Counter(x)
    y = [min(a[i], a[n - 1 - i]) + 1 for i in range(n // 2)]
    z = [max(a[i], a[n - 1 - i]) + k for i in range(n // 2)]
    y.sort()
    z.sort()
    ans = n // 2
    for i in range(2, 2 * k + 1):
        zero = x[i]
        two = bisect.bisect_left(z, i) + n // 2 - bisect.bisect_right(y, i)
        one = n // 2 - zero - two
        ans = min(ans, one + two * 2)
    print(ans)
