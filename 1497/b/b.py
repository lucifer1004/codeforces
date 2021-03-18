from collections import Counter


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m = read_ints()
    cnt = Counter(i % m for i in read_ints())
    ans = 0
    if cnt[0] > 0:
        ans += 1
    if m % 2 == 0 and cnt[m // 2] > 0:
        ans += 1
    for i in range(1, (m + 1) // 2):
        if cnt[i] > 0 or cnt[m - i] > 0:
            ans += 1
            if abs(cnt[i] - cnt[m - i]) > 1:
                ans += abs(cnt[i] - cnt[m - i]) - 1
    print(ans)
