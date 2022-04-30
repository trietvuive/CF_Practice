r,x,y,u,v=map(int,input().split())
u-=x;v-=y
d=(u*u+v*v)**.5
if d<r:
    r=(r+d)/2
    if d:
        k=r/d-1;x-=u*k;y-=v*k
    else:y+=r
print(x,y,r)
