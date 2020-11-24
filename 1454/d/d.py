def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    n0 = read_int()
    hi = 0
    hi_factor = 0
    i = 2
    n = n0
    while i * i <= n:
        freq = 0
        while n % i == 0:
            n //= i
            freq += 1
        if freq > hi:
            hi = freq
            hi_factor = i
        i += 1
    if hi == 0:
        print(1)
        print(n0)
    else:
        print(hi)
        ans = [hi_factor] * (hi - 1)
        ans.append(n0 // pow(hi_factor, hi - 1))
        print(' '.join(map(str, ans)))
