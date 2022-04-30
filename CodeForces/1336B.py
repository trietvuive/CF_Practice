import bisect
from itertools import permutations as perm
for _ in range(int(input())):
    _, ls, best = input(), [sorted(map(int, input().split())) for _ in range(3)], float("inf")
    for p in perm(ls):
        for e in p[0]:
            i,j = bisect.bisect(p[1], e, lo=1) - 1, bisect.bisect_left(p[2], e, hi=len(p[2])-1)
            best = min(best, (e-p[1][i])**2 + (e-p[2][j])**2 + (p[1][i]-p[2][j])**2)
    print(best)
