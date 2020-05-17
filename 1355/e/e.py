def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


n, a, r, m = read_ints()
h = list(read_ints())
h.sort()
lo = h[0]
hi = h[-1]
s = [0]
for i in h:
    s.append(s[-1] + i)
ans = int(1e20)
for i in range(n):
    target = h[i]
    inc = i * target - s[i]
    dec = s[n] - s[i + 1] - (n - i - 1) * target
    plan_a = inc * a + dec * r
    plan_b = (inc - dec) * a + dec * \
        m if inc >= dec else inc * m + (dec - inc) * r
    ans = min(ans, min(plan_a, plan_b))
avg = s[n] // n
for target in range(max(0, avg - 1), avg + 2):
    inc = 0
    dec = 0
    for i in h:
        if i > target:
            dec += i - target
        else:
            inc += target - i
    plan_a = inc * a + dec * r
    plan_b = (inc - dec) * a + dec * \
        m if inc >= dec else inc * m + (dec - inc) * r
    ans = min(ans, min(plan_a, plan_b))
print(ans)
