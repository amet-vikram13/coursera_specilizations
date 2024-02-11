# Uses python3
from sys import stdin

# Σ F(i)**2 = F(i)*F(i+1) // Always forms a rectangle

def pisano_period(m):
    prev, curr = 0, 1
    for i in range(m*m):
        prev, curr = curr, (prev+curr)%m
        if prev==0 and curr==1:
            return i+1

def fibonacci_huge(n):
    prev, curr = 0, 1
    if n==0 or n==1 :
    	return n
    for i in range(n-1):
        prev, curr = curr, (prev+curr)
    return curr

def fibonacci_sum_squares(n):
    if n==0:
        return 0
    if n==1:
        return 1
    #pp = pisano_period(10)
    x = n%60
    y = (n+1)%60
    a = fibonacci_huge(x)%10
    b = fibonacci_huge(y)%10
    #print(a,b)
    return (a*b)%10

if __name__ == '__main__':
    n = int(stdin.read())
    #n = int(input())
    print(fibonacci_sum_squares(n))