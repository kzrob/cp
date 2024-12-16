# correct + fast enough

# imports
import sys
import math

# i/o
input = sys.stdin.readline
print = sys.stdout.write

# execution
T = int(input())
for i in range(T):
	n = int(input())
	power = math.ceil(math.log10(n))
	
	if n<45:
		print("0\n")
		continue

	sum = 0
	for i in range(1, power-1): # 5 + 55 + ...
		sum += int("5"*i)

	min = int("4"*(power-1)+"5") # 4445
	max = int("4"+"9"*(power-1)) # 4999

	if n>=max:
		sum += int("5"*(power-1))
	elif n>=min:
		sum += n-min+1

	print(str(sum)+"\n")