index = int(input())

def printWord():
  word = input()
  cropped_word = word[1 : len(word) - 1]

  if len(word) > 10:
    print(word[0] + str(len(cropped_word)) + word[len(word) - 1])
  else:
    print(word)

for i in range(0, index):
  printWord()
