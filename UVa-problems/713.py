''' UVa 713 - Adding Reversed Numbers '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=654
# Date: 2021-08-14 17:49:01
# Run time: 0.020
# Verdict: AC

n = int(input())

for _ in range(n):
    a, b = input().strip().split()
    
    res = int(a[::-1]) + int(b[::-1])
    print(int(str(res)[::-1]))