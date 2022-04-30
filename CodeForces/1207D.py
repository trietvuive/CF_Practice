from collections import Counter
import sys

input = sys.stdin.readline

MOD = 998244353
n = int(input())
s = sorted([tuple(map(int, input().split())) for _ in range(n)])

fact = [1]
for i in range(1, n + 1):
    fact.append(fact[-1] * i % MOD) # ihy ihyt


def ways(l):
    count = Counter(l)
    res = 1
    for x in count.values():
        res = res * fact[x] % MOD
    return res

a = ways([x for x,_ in s])
b = ways([y for _,y in s])
c = ways(s) if all(s[i][1] <= s[i+1][1] for i in range(n-1)) else 0

print((fact[n] - a - b + c) % MOD)
