import  math

def GenerateSums(mx, mod):
    value = 0
    for i in range(1, mx+1):
        value = (value + i**i) % mod
    return  value

print(GenerateSums(1000, 10**10))

