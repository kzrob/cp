# i/o
import sys
input = sys.stdin.readline
print = sys.stdout.write

# functions
def evaluate(LOGIC):
    LOGIC = ' '.join(LOGIC).split(" or ")

    for i in range(len(LOGIC)):
        if LOGIC[i] == "true":
            return "true\n"
        if "false" not in LOGIC[i]:
            return "true\n"
    
    return "false\n"

# execution
N, Q = map(int, input().split())
logic = input().split(" ")
logic[N-1] = logic[N-1][:-1] #remove \n at the last string

for i in range(Q):
    query = input().split(" ")

    #get the new logic
    logicT = logic.copy()
    logicF = logic.copy()

    begin = int(query[0])-1
    end = int(query[1])

    logicT[begin] = "true"
    logicF[begin] = "false"

    for j in range(begin+1, end):
        del logicT[begin+1]
        del logicF[begin+1]
    
    #calculate new logic
    T = evaluate(logicT)
    F = evaluate(logicF)

    if T == query[2] or F == query[2]:
        print("Y")
    else:
        print("N")
