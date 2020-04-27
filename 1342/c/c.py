def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


def gcd(x, y):
    return x if y == 0 else gcd(y, x % y)


t = read_int()
for case_num in range(t):
    a, b, q = read_ints()
    g = gcd(a, b)
    lcm = a * b // g
    acc = [0 for i in range(lcm)]
    for i in range(1, lcm):
        acc[i] = acc[i - 1]
        if (i % a) % b != (i % b) % a:
            acc[i] += 1
    ans = []
    for i in range(q):
        l, r = read_ints()
        curr = 0
        n = l // lcm
        x = l % lcm
        m = r // lcm
        y = r % lcm
        if m > n + 1:
            curr += (m - n - 1) * acc[lcm - 1]
        if m > n:
            curr += acc[lcm - 1] - acc[max(0, x - 1)]
            curr += acc[y]
        if m == n:
            curr += acc[y] - acc[max(0, x - 1)]
        ans.append(curr)
    print(' '.join(map(str, ans)))
