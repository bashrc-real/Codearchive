import math
def isPerfectSquare(n):
    val = math.sqrt(n)
    return val * val == n
def f(n):
    if n == 0:
        return 0
    if isPerfectSquare(n):
        return 1
    return min((f(n-i*i) for i in range(1, int(math.sqrt(n))))) + 1  