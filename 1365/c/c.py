def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


n = read_int()
a = list(read_ints())
b = list(read_ints())
cnt = dict()
ad = dict()
bd = dict()
for i in range(n):
    ad[a[i]] = i
    bd[b[i]] = i
for i in range(1, n + 1):
    delta = (bd[i] - ad[i] + n) % n
    if not delta in cnt:
        cnt[delta] = 0
    cnt[delta] += 1
ans = 0
for key in cnt:
    ans = max(ans, cnt[key])
print(ans)
