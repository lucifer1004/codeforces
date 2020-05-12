def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    l = 1
    r = n - 1
    moves = 1
    alice = a[0]
    bob = 0
    last = a[0]
    while l <= r:
        s = 0
        if moves % 2 == 1:
            while s <= last and l <= r:
                s += a[r]
                bob += a[r]
                r -= 1

        else:
            while s <= last and l <= r:
                s += a[l]
                alice += a[l]
                l += 1
        moves += 1
        last = s
    print(moves, alice, bob)
