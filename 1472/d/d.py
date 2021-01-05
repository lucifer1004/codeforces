def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    s = sum(a)
    alice = sum(i for i in a if i % 2 == 0)
    bob = s - alice
    a.sort(reverse=True)
    bob -= sum(a[i] for i in range(n) if i % 2 == 0)
    alice -= sum(a[i] for i in range(n) if i % 2 == 1)
    if alice > bob:
        print('Alice')
    elif alice < bob:
        print('Bob')
    else:
        print('Tie')
