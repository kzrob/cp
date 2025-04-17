# during competition: incorrect + too slow
# after competition:  ?

# imports
import sys
import math
import re
import string
from collections import Counter

# i/o
input = sys.stdin.readline
print = sys.stdout.write

# input
N, F = map(int, input().split(" "))
contest = input()

# execution
alphabet = list(string.ascii_lowercase)

hashmap = {}
for i in range(N-2):
    moo = contest[i:i+3]
    hashmap[moo] = hashmap.get(moo, 0) + 1

yes = {}
maybe = {}
for k in hashmap:
    v = hashmap.get(k, 0)

    if k[0] != k[1] and k[1] == k[2]: #if ABB pattern
        if v >= F:
            yes[k] = 1
        elif v >= F-1:
            maybe[k] = 1

print(str(maybe))
print(str(hashmap))
print(contest+"\n")

for moo in maybe:
    for k in hashmap.keys():
        for c in alphabet:
            if (
                   (k[0:2] + c == moo) and (contest.index(k[0:2] + c) != contest.index(moo))
                or (k[0] + c + k[2] == moo) and (contest.index(k[0] + c + k[2]) != contest.index(moo))
                or (c + k[1:3] == moo) and (contest.index(c + k[1:3]) != contest.index(moo))
            ):
                yes[moo] = 1
                print(moo)

print(str(len(yes)) + "\n")
for v in yes.keys():
    print(v + "\n")