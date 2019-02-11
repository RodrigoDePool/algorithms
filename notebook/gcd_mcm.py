# from math import gcd ... or:
def gcd(a,b):
    if b>a: b,a=a,b
    while a%b!=0:
        a,b=b,a%b
    return b
def mcm(a,b):
    return int(a*b/gcd(a,b))
