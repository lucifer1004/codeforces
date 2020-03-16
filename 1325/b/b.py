t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    print(len(set(a)))
