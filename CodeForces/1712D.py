def diameter(lst):
    cur_mx = 0
    for i in range(1, len(lst)):
        cur_mx = max(cur_mx, min(lst[i], lst[i-1]))
    return min(cur_mx, 2 * min(lst))

def bin_search(ans, a, k):
    i = 0
    while i < len(a):
        if a[i] < ans/2:
            a[i] = 10**9
            k -= 1
        i += 1
    
    if k < 0: return False
    if k == 0: return diameter(a) >= ans
    if k == 1: return max(a) >= ans
    return True

I = lambda:list(map(int, input().split()))
tc = int(input())
for _ in range(tc):
    n,k = I()
    a = I()
    left,right = 1, 10**9
    while left < right:
        mid = (left + right + 1) // 2
        if bin_search(mid, a.copy(), k):
            left = mid
        else:
            right = mid-1
    print(left)


