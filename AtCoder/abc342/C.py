from string import ascii_lowercase
_ = int(input())
s = input()
q = int(input())
m = {l: l for l in ascii_lowercase}
for _ in range(q):
    c, d = input().split()
    new_m = dict()
    for k, v in m.items():
        if v == c:
            v = d
        new_m[k] = v
    m = new_m

print(''.join(m[x] for x in s))
