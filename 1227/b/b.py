t = int(input())
for case_num in range(t):
    n = int(input())
    q = list(map(int, input().split(' ')))
    ans = []
    used = [False for i in range(n + 1)]
    current_max = 0
    current_min = 1
    ok = True
    for i in q:
        if i > current_max:
            ans.append(i)
            used[i] = True
            current_max = i
            while current_min <= n and used[current_min]:
                current_min += 1
        else:
            if i == current_max:
                if current_min >= current_max:
                    print(-1)
                    ok = False
                    break
                ans.append(current_min)
                used[current_min] = True
                while current_min <= n and used[current_min]:
                    current_min += 1
            else:
                print(-1)
                ok = False
                break
    if ok:
        print(' '.join(map(str, ans)))
