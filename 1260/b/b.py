t = int(input())
for case_num in range(t):
    a, b = map(int, input().split(' '))
    if a > b:
        tmp = a
        a = b
        b = tmp
    print("YES" if (a + b) % 3 == 0 and a * 2 >= b else "NO")
