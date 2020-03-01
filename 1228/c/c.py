mod = 1000000007


def fexp(x, y):
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = ans * x % mod
        x = x * x % mod
        y //= 2
    return ans


def calc(x, n):
    count = 0
    while n > 0:
        count += n // x
        n //= x
    return fexp(x, count)


primes = [2, 3, 5, 7, 11, 13]
for i in range(8, 20000):
    k = 2 * i + 1
    j = 0
    prime = True
    while primes[j] * primes[j] <= k:
        if k % primes[j] == 0:
            prime = False
            break
        j += 1
    if prime:
        primes.append(k)

x, n = map(int, input().split(' '))
factors = []
for prime in primes:
    if x % prime == 0:
        factors.append(prime)
    while x % prime == 0:
        x //= prime
    if prime * prime > x:
        break
if x != 1:
    factors.append(x)

ans = 1
for factor in factors:
    ans = ans * calc(factor, n) % mod

print(ans)
