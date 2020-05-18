def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    s = input()
    cnt = dict()
    cnt['1'] = 0
    cnt['2'] = 0
    cnt['3'] = 0
    ans = len(s) + 1
    l = 0
    r = -1
    while r < len(s):
        while cnt['1'] == 0 or cnt['2'] == 0 or cnt['3'] == 0:
            r += 1
            if r >= len(s):
                break
            cnt[s[r]] += 1
        if cnt['1'] > 0 and cnt['2'] > 0 and cnt['3'] > 0:
            ans = min(ans, r - l + 1)
        cnt[s[l]] -= 1
        l += 1
    print(ans if ans <= len(s) else 0)
