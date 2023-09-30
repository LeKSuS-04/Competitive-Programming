# Verdict: AC

n = int(input())

for i in range(n + 1):
    for j in range(1, 10):
        if n % j == 0 and i % (n // j) == 0:
            print(j, end='')
            break
    else:
        print('-', end='')
print()
