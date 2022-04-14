N = 8

i = 0
num = 0
while i < N:
  num += 1
  while num % 3 == 0 or num % 5 == 0:
    num += 1
  i += 1

print(num)
