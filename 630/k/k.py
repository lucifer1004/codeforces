n = int(input())
a = n // 2
b = n // 3
c = n // 5
d = n // 7
ab = n // 6
ac = n // 10
ad = n // 14
bc = n // 15
bd = n // 21
cd = n // 35
abc = n // 30
abd = n // 42
acd = n // 70
bcd = n // 105
abcd = n // 210
rest = a + b + c + d - ab - ac - ad - bc - \
    bd - cd + abc + abd + acd + bcd - abcd
print(n - rest)
