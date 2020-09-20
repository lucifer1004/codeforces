def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    x = read_int()
    ans = 0
    level = 1
    need = 1
    while x >= need:
        x -= need
        ans += 1
        level = level * 2 + 1
        need = level * (level + 1) // 2
    print(ans)
