def read_ints():
    return map(int, input().split(' '))


n, m = read_ints()
s = []
for i in range(n):
    s.append(input())
a = list(read_ints())
ans = 0
for i in range(m):
    d = [0 for k in range(5)]
    for j in range(n):
        d[ord(s[j][i]) - ord('A')] += 1
    ans += max(d) * a[i]
print(ans)
