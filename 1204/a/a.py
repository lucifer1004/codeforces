t = int(input(), 2) - 1
ans = 0
while t > 0:
    ans += 1
    t //= 4
print(ans)
