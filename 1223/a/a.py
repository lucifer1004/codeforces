t = int(input())
for case_num in range(t):
    n = int(input())
    if n < 4:
        print(4 - n)
    else:
        print(n % 2)
