import os
import sys

inp = lambda : input()
ri = lambda : int(inp())

def solve():
    n = ri()
    p = 10**(n//2)
    for i in range(n//2):
        print((p + 3*10**i) ** 2)
        print((3*p + 10**i) ** 2)

    print((p + 4*p//10) ** 2)

    return 0

tc = ri()
for _ in range(tc):
    solve()

