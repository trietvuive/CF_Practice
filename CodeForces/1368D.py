n = int(input())
a = [int(x) for x in input().split()]
l = [0]*n

for i in range(20):
    for j in range(sum([x>>i&1 for x in a])):
        l[j] |= 1 << i

print(sum([x*x for x in l]))
