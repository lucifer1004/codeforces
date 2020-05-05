m = int(input())
for case_num in range(m):
    n, T, a, b = map(int, input().split(' '))
    d = list(map(int, input().split(' ')))
    t = list(map(int, input().split(' ')))
    critical = set()
    for ti in t:
        critical.add(ti)
        if ti >= 1:
            critical.add(ti - 1)
    critical.add(T)
    critical = list(critical)
    critical.sort()
    k = len(critical)
    lut = dict()
    for i in range(k):
        lut[critical[i]] = i
    easy = [0 for i in range(k)]
    hard = [0 for i in range(k)]
    for i in range(n):
        idx = lut[t[i]]
        if d[i] == 0:
            easy[idx] += 1
        else:
            hard[idx] += 1
    mandatory_easy = 0
    mandatory_hard = 0
    total_hard = sum(d)
    total_easy = n - total_hard
    ans = 0
    for i in range(k):
        mandatory_easy += easy[i]
        mandatory_hard += hard[i]
        time = critical[i] - mandatory_easy * a - mandatory_hard * b
        if time < 0:
            continue
        rest_easy = total_easy - mandatory_easy
        extra_easy = min(time // a, rest_easy)
        time -= extra_easy * a
        rest_hard = total_hard - mandatory_hard
        extra_hard = min(time // b, rest_hard)
        score = mandatory_easy + mandatory_hard + extra_easy + extra_hard
        ans = max(ans, score)
    print(ans)
