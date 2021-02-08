M,a,b=int(1e9+7),0,1
m=bin(int(input()))[2:]
for i in m:
    a,b=(a*(b*2-a))%M,(a*a+b*b)%M
    if i=='1':
        a,b=b%M,(a+b)%M
print(a)