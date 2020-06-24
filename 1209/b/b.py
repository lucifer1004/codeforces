n = int(input())
lights = input()
lights = [c for c in lights]
a = []
b = []
for i in range(n):
    (ai, bi) = map(int, input().split(' '))
    a.append(ai)
    b.append(bi)
ans = lights.count('1')
for t in range(1, 1000):
    for i in range(n):
        if t >= b[i] and (t - b[i]) % a[i] == 0:
            lights[i] = '1' if lights[i] == '0' else '0'
    ans = max(ans, lights.count('1'))
print(ans)
