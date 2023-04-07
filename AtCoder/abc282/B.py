''' B - Let's Get a Perfect Score '''
# https://atcoder.jp/contests/abc282/tasks/abc282_b
# Date: 2022-12-17 15:04:06
# Run time: 23 ms
# Memory: 9128 KB	
# Verdict: AC

n, m = map(int, input().split())

solves = [input() for _ in range(n)]

cnt = 0
for i in range(n):
    for j in range(i+1, n):
        if all(solves[i][k] == 'o' or solves[j][k] == 'o' for k in range(m)):
            cnt += 1

print(cnt)