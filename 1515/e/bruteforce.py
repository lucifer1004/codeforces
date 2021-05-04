from itertools import combinations, permutations

for n in range(3, 11):
    valid = 0
    for m in range(1, n + 1):
        for c in combinations(list(range(n)), m):
            for a in permutations(c):
                vis = [False] * n
                is_valid = True
                covered = 0
                for i in a:
                    if vis[i]:
                        is_valid = False
                        break
                    vis[i] = True
                    covered += 1
                    if i >= 2 and vis[i - 2] and not vis[i - 1]:
                        vis[i - 1] = True
                        covered += 1
                    if i + 2 < n and vis[i + 2] and not vis[i + 1]:
                        vis[i + 1] = True
                        covered += 1

                if is_valid and covered == n:
                    valid += 1
    print(n, valid)
