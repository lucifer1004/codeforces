def dsum(n):
    return sum([int(c) for c in str(n)])


n, s = map(int, input().split(' '))
l = 1
r = n
while l <= r:
    mid = (l + r) // 2
    delta = mid - dsum(mid)
    if delta >= s:
        r = mid - 1
    else:
        l = mid + 1
print(n - l + 1)
