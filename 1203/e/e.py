maxp = 150001
n = int(input())
a = list(map(int, input().split(' ')))
b = [0] * (maxp + 1)
c = [0] * (maxp + 1)
for i in a:
    b[i] += 1
for i in range(1, maxp):
    if b[i] == 0:
        continue
    if i > 1 and b[i - 1] + c[i - 1] == 0:
        c[i - 1] = 1
        b[i] -= 1
    if b[i] + c[i] > 0:
        remain = 1 if c[i] == 0 else 0
        c[i + 1] += b[i] - remain
        b[i] = remain
ans = 0
for i in range(maxp + 1):
    if b[i] + c[i] > 0:
        ans += 1
print(ans)
