from functools import *

@cache
def BC(n, k, m):
    if n == 0:
        return 1 if k == 0 else 0
    if k == 1:
        return 1 if n <= m else 0
    
    r = 0    
    for x in range(1, min(n, m)+1):
        r += BC(n-x, k-1, m)
    return r

while True:
    try:
        n, k, m = map(int, input().split())
    except:
        break
    print(BC(n, k, m))

    
