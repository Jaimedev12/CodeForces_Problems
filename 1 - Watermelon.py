w = int(input())

if w < 1 or w > 100:
    exit()
elif (w - 2) % 2 == 0 and (w - 2) != 0:
    print("YES")
else:
    print("NO")
