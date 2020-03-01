t = int(input())
for case_num in range(t):
    s = input()
    ss = set([c for c in s])
    t = input()
    st = set([c for c in t])
    print("YES" if len(ss.intersection(st)) > 0 else "NO")
