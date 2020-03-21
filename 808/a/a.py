x = input()
l = len(x)
y = int(x)
r = 10 ** (l - 1)
ans = (y // r + 1) * r - y
print(ans)
