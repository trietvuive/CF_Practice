I = lambda:list(map(int, input().split()))
n,= I()
a = I()
b = I()
c = I()
before = a[0] # choosing this before the next element
after = b[0] # choosing this after the next element
for i in range(1,n):
    before, after = max(after + a[i], before + b[i]), max(after + b[i], before + c[i])
print(before)
