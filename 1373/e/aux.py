# Prove that all modulo can be covered.

d = [i % 10 for i in range(20)]
for k in range(1, 11):
    c = set()
    print(c)
    for i in range(10):
        s = 0
        for j in range(i, i + k):
            s += d[j]
        if i + k >= 10:
            right = i + k - 9
            left = k - right
            s += left
            c.add(s % k)
    print(k, c)
