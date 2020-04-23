def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    a = list(read_ints())
    s = [0]
    for i in range(n):
        is_peak = False
        if 1 <= i < n - 1:
            if a[i] > a[i - 1] and a[i] > a[i + 1]:
                is_peak = True
        s.append(s[-1] + (1 if is_peak else 0))
    mp = 0
    ans = 0
    for l in range(n - k + 1):
        peaks = s[l + k - 1] - s[l + 1]
        if peaks > mp:
            mp = peaks
            ans = l
    print(mp + 1, ans + 1)
