import math
from functools import lru_cache

# k is marbles remaining, c is bags remaining

@lru_cache(maxsize=None)
def choose_3(k,c):
    if c*3 < k or k < 0:
        return 0
    if c == 1:
        return math.comb(3,k)
    res = choose_3(k,c-1) + 3*choose_3(k-1,c-1) + 3*choose_3(k-2,c-1)
    print("choose %d from %d bags = %d" % (k, c, res))
    return res

@lru_cache(maxsize=None)
def choose_2(k,c):
    if c*2 < k or k < 0:
        return 0
    if c == 1:
        return math.comb(2,k)
    return choose_2(k,c-1) + 2*choose_2(k-1,c-1)

@lru_cache(maxsize=None)
def choose_large(edges_central,edges_removed):
    return math.comb(edges_central, edges_removed)


n = int(input())

edges = 2 * (n - 1) - 1
edges_to_eliminate = edges - n

ans = 0

two_count = 2
three_count = edges - 2 - 1
edges_central = n - 1
print("Edges: ", edges_to_eliminate)

for two_marbles in range(5):
    for large_marbles in range(edges_to_eliminate - two_marbles + 1):
        three_marbles = edges_to_eliminate - two_marbles - large_marbles
        two_ways = choose_2(two_marbles, two_count)
        three_ways = choose_3(three_marbles, three_count)
        large_way = choose_large(edges_central, large_marbles)
        print(two_marbles, three_marbles, large_marbles)
        print(two_ways, three_ways, large_way)
        print()
        ans += two_ways * three_ways * large_way

print(ans)


