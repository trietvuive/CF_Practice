def i(): return map(float, raw_input().split())
n,a,d = i()
r = 0
while n:
    n-=1
    t,v = i()
    # first leg: accelerate all the way to v
    # second leg: (d - v/2 * v/a) / v
    r = max(r, t + min((2*d/a)**.5,v/a) + max(0,d/v-v/2/a))
    print(r)
