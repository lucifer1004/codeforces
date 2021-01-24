def read_int():
    return int(input())


def is_prime(n):
    if n == 1:
        return False
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


t = read_int()
for case_num in range(t):
    d = read_int()
    p1 = 1 + d
    while not is_prime(p1):
        p1 += 1
    p2 = p1 + d
    while not is_prime(p2):
        p2 += 1
    print(p1 * p2)
