from collections import Counter

t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    c = Counter(a)
    distinct = len(c)
    hi = 0
    for key in c:
        hi = max(hi, c[key])
    if distinct > hi:
        print(hi)
    elif distinct == hi:
        print(hi - 1)
    else:
        print(distinct)
