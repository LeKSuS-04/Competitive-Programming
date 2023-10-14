# Verdict: AC
n = int(input())

i = 0
while 2**i <= n:
    j = 0
    while 2**i * 3**j <= n:
        if 2**i * 3**j == n:
            print('Yes')
            exit(0)
        j += 1
    i += 1
print('No')