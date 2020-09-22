M=int(1e9+7)

fib={0:0,1:1}

def f(x):
    x=int(x)
    if x in fib:
        return fib[x]
    if x-1 in fib and x-2 in fib:
        fib[x]=(fib[x-1]+fib[x-2])%M
        return fib[x]
    if x%2 :
        fib[x]=(f(x//2)*f(x//2)+f(x//2+1)*f(x//2+1))%M
        return fib[x]
    f(x//2-1)
    f(x//2)
    f(x//2+1)
    fib[x]=fib[x//2]*(fib[x//2-1]+fib[x//2+1])%M
    return fib[x]

n=int(input())
print(f(n))