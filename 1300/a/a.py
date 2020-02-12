t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    sum = 0
    count = 0
    for i in a:
        if i == 0:
            sum += 1
            count += 1
        else:
            sum += i
    if sum == 0:
        count += 1
    print(count)
