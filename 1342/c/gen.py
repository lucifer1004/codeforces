from random import randint

t = 100
a = 200
b = 200
q = 500
print(t)
for i in range(t):
    print(a, b, q)
    for j in range(q):
        l = randint(1, int(1e17))
        r = randint(l + 1, int(1e18))
        print(l, r)
