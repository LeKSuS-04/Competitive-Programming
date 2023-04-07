''' B - Everyone is Friends '''
# https://atcoder.jp/contests/abc272/tasks/abc272_b
# Date: 2022-10-08 15:07:13
# Run time: 56 ms
# Memory: 9072 KB
# Verdict: AC

n, m = map(int, input().split())

parties = [[] for _ in range(m)]
for i in range(m):
    parties[i] = list(map(int, input().split()))[1:]
    
for a in range(1, n+1):
    for b in range(1, n+1):
        if a != b:
            for party in parties:
                if a in party and b in party:
                    break
            else:
                print('No')
                exit(0)
print('Yes')
