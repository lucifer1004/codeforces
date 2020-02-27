x = int(input())
v = 0
a = []
for i in range(4):
    angle = ((i * 90 - x) % 360 + 360) % 360
    a.append(min(angle, 360 - angle))
    if a[i] < a[v]:
        v = i
print(v)
