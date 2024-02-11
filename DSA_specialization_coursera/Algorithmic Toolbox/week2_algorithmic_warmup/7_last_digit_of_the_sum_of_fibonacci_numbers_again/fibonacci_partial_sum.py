# Uses python3
import sys

## Sm,n = F(n+2)-F(m+1)

def pisano_period(m) :
    prev, curr = 0, 1
    for i in range(m*m) :
        prev, curr = curr, (curr+prev)%m
        if prev==0 and curr==1:
            return i+1

def fibonacci_sum(n):
    prev, curr = 0, 1
    for i in range(n-1):
        prev, curr = curr, (prev+curr)
    return curr


def fibonacci_partial_sum(from_, to):
    pp = pisano_period(10)
    from_ = from_%pp
    to = to%pp
    return (fibonacci_sum(to+2)-fibonacci_sum(from_+1))%10


if __name__ == '__main__':
    input = sys.stdin.read();
    from_, to = map(int, input.split())
    print(fibonacci_partial_sum(from_, to))