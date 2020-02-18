s = input()
d1 = dict()
d2 = dict()
for c in s:
    for key in d1:
        if key + c in d2:
            d2[key + c] += d1[key]
        else:
            d2[key + c] = d1[key]
    if c in d1:
        d1[c] += 1
    else:
        d1[c] = 1
ans = 0
for key in d1:
    ans = max(ans, d1[key])
for key in d2:
    ans = max(ans, d2[key])
print(ans)
