''' B - V '''
# https://atcoder.jp/contests/abc289/tasks/abc289_b
# Date: 2023-02-11 15:11:07
# Run time: 24 ms
# Memory: 9044 KB
# Verdict: AC

n, m = map(int, input().split())
s = sorted(list(map(int, input().split())))
out = []
i = 1
while i <= n:
    if i in s:
        tmp = [i]
        i += 1
        while i - 1 in s:
            tmp.append(i)
            i += 1
        out += reversed(tmp)
    else:
        out.append(i)
        i += 1

print(*out)
