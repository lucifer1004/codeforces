from collections import defaultdict


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    input()
    n, m = read_ints()
    blocks = defaultdict(int)
    blocks[0] = 3
    blocks[n + 1] = 3
    for i in range(m):
        r, c = read_ints()
        blocks[c] += r
    keys = sorted(list(blocks.keys()))
    l = len(keys)
    black = 0
    white = 0
    singles = []
    valid = True

    def validate(singles):
        m = len(singles)
        for i in range(m):
            l, r, c = singles[i]
            if (r - l + 1) % 2 == 0:
                continue
            if i < m - 1:
                code = (singles[i + 1][0] - r - 1) + (c + singles[i + 1][2])
                if code % 2 != 0:
                    return False
                singles[i + 1][0] += 1
        return True

    for i in range(1, l):
        left = keys[i - 1]
        col = keys[i]
        if keys[i - 1] < col - 1:
            if blocks[col] == 3:
                if black != white:
                    valid = False
                    break
                if not validate(singles):
                    valid = False
                    break
                black = 0
                white = 0
                singles = []
            else:
                cell = blocks[col] + col
                if cell % 2 == 0:
                    white += 1
                else:
                    black += 1
                singles.append([col, col, blocks[col]])
        else:
            if blocks[left] == 3 or blocks[col] == 3 or blocks[col] + blocks[left] == 3:
                if black != white:
                    valid = False
                    break
                if not validate(singles):
                    valid = False
                    break
                black = 0
                white = 0
                singles = []
            if blocks[col] < 3:
                cell = blocks[col] + col
                if cell % 2 == 0:
                    white += 1
                else:
                    black += 1
                if len(singles) == 0:
                    singles.append([col, col, blocks[col]])
                else:
                    singles[-1][1] = col

    print('YES' if valid else 'NO')
