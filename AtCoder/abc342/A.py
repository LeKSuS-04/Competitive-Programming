s = input()
a, b = set(s)
if s.count(a) == 1:
    print(1 + s.index(a))
else:
    print(1 + s.index(b))