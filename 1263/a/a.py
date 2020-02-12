t = int(input())
for case_num in range(t):
    a = list(map(int, input().split(' ')))
    a.sort()
    if a[0] + a[1] <= a[2]:
        print(a[0] + a[1])
    else:
        print((a[0] + a[1] + a[2]) // 2)
