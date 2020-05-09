def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    a = input()
    b = input()
    a = a[::-1]
    b = b[::-1]
    ans = 0
    l = 0
    while b[l] == '0':
        l += 1
    r = 0
    while a[r] == '0' or r < l:
        r += 1
    print(0 if l >= r else r - l)
