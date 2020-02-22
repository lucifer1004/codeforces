t = int(input())
for case_num in range(t):
    a, b = map(int, input().split(' '))
    if a >= b or a >= 4 or (a == 2 and b == 3):
        print("YES")
    else:
        print("NO")
