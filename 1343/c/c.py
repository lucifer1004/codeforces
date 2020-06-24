t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    b = []
    for i in a:
        if len(b) == 0 or b[-1][0] * i < 0:
            b.append([i])
        else:
            b[-1].append(i)
    print(sum([max(interval) for interval in b]))
