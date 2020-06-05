def read_int():
    return int(input())


t = read_int()
ans = []
for case_num in range(t):
    n = int(input())
    ans.append(n * 2 - bin(n).count('1'))
print('\n'.join(map(str, ans)))
