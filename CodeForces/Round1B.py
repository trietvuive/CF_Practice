inp = open('in/sample.txt', 'r')
oup = open('out/sample.txt', 'w')
tc = int(inp.readline())
I = lambda: list(map(int, inp.readline().split()))

def solve():
    n = int(inp.readline())
    square_a, square_b, sum_a, sum_b = 0,0,0,0
    for i in range(n):
        a,b = I()
        square_a += a*a
        square_b += b*b
        sum_a += a
        sum_b += b

    ans = 0
    q = int(inp.readline())
    for i in range(q):
        a,b = I()
        ans += square_a + square_b
        ans -= 2*a*sum_a + 2*b*sum_b
        ans += n*a*a + n*b*b

    return ans % (10**9 + 7)

for i in range(1, tc+1):
    ans = solve()
    oup.write(f"Case #{i}: {ans}")
    oup.write('\n')

inp.close()
oup.close()
