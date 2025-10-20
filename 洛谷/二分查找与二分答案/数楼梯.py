n=int(input())
f=[0 for i in range(1,n+10,1)]
f[0]=1
f[1]=1
if n==0:
    print(0)
else:
    for i in range(1,n+1):
        f[i]=f[i-1]+f[i-2]
    print(f[n])
# c++得用高精度 还不会