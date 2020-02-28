n = int(input())
a = list(map(int, input().split(' ')))
same = [n - a[i] for i in range(n)]
color = [-1 for i in range(n)]
assigned = [0 for i in range(n + 1)]
current = dict()
last_color = 1
for i in range(n):
    if (same[i] in current and assigned[same[i]] == same[i]) or (not same[i] in current):
        current[same[i]] = last_color
        last_color += 1
        assigned[same[i]] = 0
    color[i] = current[same[i]]
    assigned[same[i]] += 1
ok = True
for num in range(2, n + 1):
    if assigned[num] % num != 0:
        ok = False
        break
if ok:
    print("Possible")
    print(' '.join(map(str, color)))
else:
    print("Impossible")
