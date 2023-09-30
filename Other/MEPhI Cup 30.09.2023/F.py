# Verdict: AC
s = input()

l = 0
r = len(s)
if s[l] != '0':
    print('No')

else:
    l += 1

    while s[l:l + 2] == '01' and l < r:
        l += 2

    while s[r - 3:r] == '010' and l < r - 3:
        r -= 3

    left = s[l:r]
    if len(left) == 2 and left.startswith('1'):
        print('Yes')
    else:
        print('No')
