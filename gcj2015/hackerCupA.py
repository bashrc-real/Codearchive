import math

def solve():
    p,x,y = input().split(' ')
    p,x,y=int(p),int(x) - 50,int(y) - 50
    if p == 0:
        return False
    angle = math.atan2(y,x)
    piAngle = (p*360)/100.0
    if piAngle > 180:
        piAngle = 180 - piAngle
    piAngle = (piAngle * math.pi/180.0)
    return piAngle - angle >= 1e-6 and (x*x+y*y) <= 50*50


t = int(input())
for i in range(0,t):
    print("Case #"+ str(i+1)+": ", "black" if solve() else "white")


