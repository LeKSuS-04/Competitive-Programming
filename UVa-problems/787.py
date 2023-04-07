''' UVa 787 - Maximum Sub-sequence Product '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=728
# Date: 2021-10-04 17:28:52
# Runtime: 0.010
# Verdict: AC

import sys

for line in sys.stdin:
    nums = list(map(int, line.split()[:-1]))

    minv = nums.copy()
    maxv = nums.copy()

    for i in range(1, len(nums)):
        a, b = minv[i - 1] * nums[i], maxv[i - 1] * nums[i]
        minv[i] = min(a, b, minv[i])
        maxv[i] = max(a, b, maxv[i])

    print(max(maxv))

