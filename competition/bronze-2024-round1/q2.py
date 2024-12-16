# during competition: incorrect + too slow
# after competition:  correct, but too slow

# imports
import sys
import math

# i/o
input = sys.stdin.readline
print = sys.stdout.write

# execution
N, Q = map(int, input().split(" "))

array = []
pairs = []
for i in range(Q):
	coords = list(map(int, input().split(" ")))
	array.append(coords)

for i in range(len(array)):
	matched = False
	for j in range(i): # for all the other arrays
		matches = 0
		noMatch = None
		for c in range(3):
			if array[j][c] == array[i][c]:
				matches += 1
			else:
				noMatch = c
		if matches >= 2 and abs(array[i][noMatch]-array[j][noMatch]) == 1: # short circuit utilization ensures noMatch will be set only once
			pairs.append([i, j])
			matched = True
	if matched == False:
		pairs.append([i])

	groups = 0
	nums = 0
	for group in pairs:
		groups += 1
		for num in group:
			nums += 1
	print(str(nums-groups) + "\n")
