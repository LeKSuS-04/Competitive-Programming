''' A - Probably English '''
# https://atcoder.jp/contests/abc295/tasks/abc295_a
# Date: 2023-03-25 15:01:02
# Run time: 25 ms
# Memory: 8728 KB
# Verdict: AC

_ = input()
w = input().split()

if any(word in w for word in 'and,not,that,the,you'.split(',')):
    print('Yes')
else:
    print('No')