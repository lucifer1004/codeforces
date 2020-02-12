t = int(input())
for case_num in range(t):
    n = int(input())
    pin = []
    cnt = dict()
    for i in range(n):
        pin.append(input())
        if pin[i] in cnt:
            cnt[pin[i]].append(i)
        else:
            cnt[pin[i]] = [i]
    ans = 0
    updated = cnt.copy()
    for key in cnt:
        if len(cnt[key]) > 1:
            dup = len(cnt[key]) - 1
            ans += dup
            for i in range(dup):
                for tail in range(10):
                    new = pin[cnt[key][i]][0:3] + str(tail)
                    if not new in updated:
                        pin[cnt[key][i]] = new
                        updated[new] = []
                        break
    print(ans)
    for key in pin:
        print(key)
