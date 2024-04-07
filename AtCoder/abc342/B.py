n = int(input())
p = [int(x) for x in input().split()]
q = int(input())
for _ in range(q):
    a, b = map(int, input().split())
    if p.index(a) < p.index(b):
        print(a)
    else:
        print(b)
