l,r = map(int,input().split())
print(2**(l^r).bit_length() - 1)
