#1230 MODEX

def big_exp(a, b, c):
    if b == 0:
        return 1
    half_exp = big_exp(a, b // 2, c)
    half_exp = (half_exp * half_exp) % c
    if b % 2 == 1:
        half_exp = (half_exp * a) % c
    return half_exp

T = int(input())
while T:
    T -= 1
    a, b, c = map(int, input().split())
    print(big_exp(a, b, c))
_ = input()