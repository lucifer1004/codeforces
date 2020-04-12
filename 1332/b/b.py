t = int(input())
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    used = set()
    color = []
    for i in a:
        for prime in primes:
            if i % prime == 0:
                color.append(prime)
                used.add(prime)
                break
    lookup = dict()
    idx = 1
    for c in used:
        lookup[c] = idx
        idx += 1
    print(len(used))
    print(' '.join(map(str, [lookup[i] for i in color])))
