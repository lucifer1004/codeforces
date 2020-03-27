from collections import Counter

inf = int(1e18)
n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
cnt = Counter(a)
b = list(cnt)
b.sort()
ok = False
for i in b:
    if cnt[i] >= k:
        print(0)
        ok = True
        break
if not ok:
    ans = inf
    m = len(b)
    b = [0] + b + [inf]
    cnt[0] = 0
    cnt[inf] = 0
    left_count = [0] * (m + 1)
    left_sum = [0] * (m + 1)
    right_count = [0] * (m + 1)
    right_sum = [0] * (m + 1)
    for i in range(2, m + 1):
        left_count[i] = left_count[i - 1] + cnt[b[i - 1]]
        left_sum[i] = left_sum[i - 1] + left_count[i - 1] + \
            left_count[i] * (b[i] - b[i - 1] - 1)
    for i in range(m - 1, 0, -1):
        right_count[i] = right_count[i + 1] + cnt[b[i + 1]]
        right_sum[i] = right_sum[i + 1] + right_count[i + 1] + \
            right_count[i] * (b[i + 1] - b[i] - 1)
    for i in range(1, m + 1):
        target = k - cnt[b[i]]
        use_left = inf
        use_right = inf
        if left_count[i] >= target:
            use_left = left_sum[i] + target
        if right_count[i] >= target:
            use_right = right_sum[i] + target
        use_both = left_sum[i] + right_sum[i] + target
        cost = min(use_left, use_right, use_both)
        ans = min(ans, cost)
    print(ans)
