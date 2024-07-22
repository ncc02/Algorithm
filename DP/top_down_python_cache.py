# Solution UVA: 10943 - How do you add?
 

# Problem	  Verdict	Lang	Time	Best	Rank	Submit Time
#  | discuss10943 - How do you add?	 Accepted	Python	0.160	0.000	4199	35 secs ago


# Suggest:
# - This problem similar with problem 10721 - Bar Codes
# We have fomular f(n, k) = f(n-i, k-1) | i = 0 -> n

# - Example: 
# f(2,2) = f(2,1) + f(1, 1) + f(0, 1) 

# f(0, 1) = 0
# f(1, 1) = f(1, 0) + f(0, 0) = 0 + 1 = 1
# f(2, 1) = f(2, 0) + f(1, 0) + f(0, 0) = 0 + 1 + 1 = 2

# => f(2, 2) = 0 + 1 + 2 = 3 

from functools import cache

@cache
def f(n, k, m):
    if n < 0 or k < 0:
        return 0
    if n == 0 and k == 0:
        return 1
    
    r = 0
    for i in range(0, n+1):
        r = (r + f(n-i, k-1, m) % m) % m
    return r

while True:
    n, k = map(int, input().split())
    if n==0 and k==0:
        break
    print(f(n, k, 1000000))


# 10721 - Bar Codes
# from functools import *

# @cache
# def BC(n, k, m):
#     if n == 0:
#         return 1 if k == 0 else 0
#     if k == 1:
#         return 1 if n <= m else 0
    
#     r = 0    
#     for x in range(1, min(n, m)+1):
#         r += BC(n-x, k-1, m)
#     return r

# while True:
#     try:
#         n, k, m = map(int, input().split())
#     except:
#         break
#     print(BC(n, k, m))

    
