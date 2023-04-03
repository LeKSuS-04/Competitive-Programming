''' A - Alternately '''
# https://atcoder.jp/contests/abc296/tasks/abc296_a
# Date: 2023-04-01 15:01:01
# Run time: 25 ms
# Memory: 9076 KB
# Verdict: AC

_ = int(input())
s = input()

for i in range(1, len(s)):
    if s[i] == s[i - 1]:
        print('No')
        exit()
print('Yes')