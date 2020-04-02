n = int(input())
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
ans = []
for prime in primes:
    if n % prime == 0:
        print('{}{}'.format(prime, n // prime))
        break