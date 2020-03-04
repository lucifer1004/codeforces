s = input()
l = 0
r = len(s) - 1
a = []
while l < r:
    while l < len(s) and s[l] != '(':
        l += 1
    while r >= 0 and s[r] != ')':
        r -= 1
    if l < r:
        a.append(l + 1)
        a.append(r + 1)
        l += 1
        r -= 1
if len(a) == 0:
    print(0)
else:
    a.sort()
    print(1)
    print(len(a))
    print(' '.join(map(str, a)))
