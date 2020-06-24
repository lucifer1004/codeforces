t = int(input())
a = [3]
for i in range(2, 30):
    a.append(a[-1] + 2 ** i)
for case_num in range(t):
    n = int(input())
    for j in a:
        if n % j == 0:
            print(n // j)
            break
