t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    color = [1] * n
    if len(set(a)) == 1:
        print(1)
        print(' '.join(map(str, color)))
    else:
        one = [False] * n
        two = [False] * n
        one[0] = True
        for i in range(n - 1):
            if a[i] == a[i + 1]:
                color[i + 1] = color[i]
            else:
                color[i + 1] = 3 - color[i]
        if a[0] == a[n - 1] or color[0] != color[n - 1]:
            print(2)
            print(' '.join(map(str, color)))
        else:
            backup = color.copy()
            color[n - 1] = 2
            i = n - 2
            while i >= 0 and a[i] != a[i + 1] and color[i] == color[i + 1]:
                color[i] = 3 - color[i + 1]
                i -= 1
            if color[0] == 1:
                print(2)
                print(' '.join(map(str, color)))
            else:
                backup[n - 1] = 3
                print(3)
                print(' '.join(map(str, backup)))
