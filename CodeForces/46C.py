n=int(input())
s=input()
h=s.count('H')
print(min((s+s)[i:i+h].count('T') for i in range(n)))
