# Uses python3
import sys

'''
Sn = Fn+2 - 1
'''

def pisano_period(m) :
	prev, curr = 0, 1
	for i in range(m*m) :
		prev, curr = curr, (curr+prev)%m
		if prev==0 and curr==1 :
			return i+1

def fibonacci_sum(n):
	pp = pisano_period(10)
	n = n%pp
	prev, curr = 0, 1
	for i in range(n+1) :
		prev, curr = curr,(prev+curr)
	return (curr-1)%10
	
if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(fibonacci_sum(n))
