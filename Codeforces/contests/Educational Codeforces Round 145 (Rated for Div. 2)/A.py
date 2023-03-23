''' 1809A. Garland '''
# https://codeforces.com/contest/1809/problem/A
# Date: Mar/23/2023 17:41
# Run time: 218 ms
# Memory: 7120 KB
# Verdict: AC

TC = int(input())
for _ in range(TC):
    s = input()
    diff = len(set(s))
    if diff == 1:
        print(-1)
    elif diff == 2 and s.count(s[0]) in [1, 3]:
        print(6)
    else:
        print(4)
