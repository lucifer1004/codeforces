b = int(input())
g = int(input())
n = int(input())
ans = 0
for i in range(0, n + 1):
    blue = i
    red = n - i
    if blue <= b and red <= g:
        ans += 1
print(ans)
