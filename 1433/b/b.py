def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    l = 0
    while l < n and a[l] == 0:
        l += 1
    r = n - 1
    while r >= 0 and a[r] == 0:
        r -= 1
    if l > r:
        print(0)
        continue
    ones = sum(a[l:r+1])
    print(r - l + 1 - ones)
