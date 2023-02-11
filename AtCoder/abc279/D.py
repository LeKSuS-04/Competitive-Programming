from math import sqrt

A, B = map(int, input().split())

def f(x):
    return A/sqrt(1 + x) + B*x

e = 1e-6/2
l = e
r = A
while r - l > 3:
    m1 = int(1*(r - l)/3 + l)
    m2 = int(2*(r - l)/3 + l)
    if f(m1) < f(m2):
        r = m2
    else:
        l = m1


answer = min(f(g) for g in range(max(0, l - 5), r + 5))
print(f'{answer:.09f}')

