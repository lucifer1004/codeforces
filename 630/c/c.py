n = int(input())
ans = 0
curr = 2
for i in range(n):
    ans += curr
    curr *= 2
print(ans)
