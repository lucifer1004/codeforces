inc = 1.000000011
n, t = map(int, input().split(' '))
fold = 1.0
while t > 0:
    if t % 2 == 1:
        fold *= inc
    inc *= inc
    t = t // 2
print(n * fold)
