n = int(input())
ans = 0
layer = 0
while True:
    layer += 1
    rem = 2 * layer % 3
    if n % 3 != rem:
        continue
    least = 3 * layer * (layer + 1) // 2 - layer
    if n < least:
        break
    ans += 1
print(ans)
