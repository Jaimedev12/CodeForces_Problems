numberOfOp = int(input())
x = 0

for operation in range(0, numberOfOp):
    operation = input()

    if "++" in operation:
        x += 1
    elif "--" in operation:
        x -= 1
    else:
        print("Not valid operation")
print(x)