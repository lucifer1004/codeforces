from math import floor


def read_int():
    return int(input())


n = read_int()
p = int(floor(n ** 0.1))
cnt = [p for i in range(10)]
tot = p ** 10
idx = 0
while tot < n:
    cnt[idx] += 1
    tot = tot // p * (p + 1)
    idx += 1
s = 'codeforces'
ans = []
for i in range(10):
    for j in range(cnt[i]):
        ans.append(s[i])
print(''.join(ans))
