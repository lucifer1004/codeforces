def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    if n == 1:
        print(0)
    else:
        two = 0
        three = 0
        while n % 2 == 0:
            n //= 2
            two += 1
        while n % 3 == 0:
            n //= 3
            three += 1
        if n != 1 or two > three:
            print(-1)
        else:
            print(three * 2 - two)
