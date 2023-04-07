''' A - 484558 '''
# https://atcoder.jp/contests/abc271/tasks/abc271_a
# Date: 2022-10-01 15:02:08
# Run time: 62 ms	
# Memory: 61588 KB	
# Verdict: AC

n = int(input())

k = hex(n)[2:]
print(f'{k:>02}'.upper())