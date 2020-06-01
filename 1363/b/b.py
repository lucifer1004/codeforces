def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    s = input()
    n = len(s)
    one = [0 for i in range(n + 1)]
    zero = [0 for i in range(n + 1)]
    for i in range(n):
        one[i + 1] = one[i] + (1 if s[i] == '1' else 0)
        zero[i + 1] = zero[i] + (1 if s[i] == '0' else 0)
    ans = n
    for i in range(n + 1):
        cost = min(one[i] + zero[n] - zero[i], zero[i] + one[n] - one[i])
        ans = min(ans, cost)
    print(ans)
