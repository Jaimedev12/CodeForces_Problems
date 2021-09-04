numberOfProblems = int(input()) #Enter the number of problem they will solve
counter = 0

for i in range(0, numberOfProblems):
  certainty = str(input()) # Enter the certainty
  amiga1 = int(certainty[0])
  amiga2 = int(certainty[2])
  amiga3 = int(certainty[4])
  amigat = amiga1 + amiga2 + amiga3

  if amigat >= 2:
      counter += 1
  else:
      counter = counter

print(counter)
