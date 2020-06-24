def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


from functools import lru_cache


@lru_cache(None)
def solve(n):
    if n == 1:
        return False
    if n % 2 == 1 or n == 2:
        return True
    m = 0
    while n % 2 == 0:
        n //= 2
        m += 1
    if m >= 2 and n == 1:
        return False
    idx = 3
    prime = True
    while idx * idx <= n:
        if n % idx == 0:
            prime = False
            break
        idx += 1
    return m >= 2 or (not prime)


t = read_int()
for case_num in range(t):
    n = read_int()
    print("Ashishgup" if solve(n) else "FastestFinger")
