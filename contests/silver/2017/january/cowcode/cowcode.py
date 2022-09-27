from math import ceil, log2

def size(n):
  # 1 << x is the same thing as 2^x. Why? Because of bits, of course.
  return (1 << n) * len(s)

def f(n, i):
  # first condition - we can just return to make the rest of the code cleaner
  if n == 0:
    return s[i]
  
  # second condition (first part of string)
  if i < size(n - 1):
    return f(n - 1, i)

  # everything else has been subtracted by the previous iteration value,
  # just to make our lives easier - the math is still the exact same.
  half = size(n - 1)
  i -= half
  
  # third condition (second part of string)
  if i == 0:
    return f(n - 1, half - 1)
  
  # fourth condition (third part of string)
  return f(n - 1, i - 1)


# Input
fin = open("cowcode.in", "r")
line = fin.readline().split(" ")
fin.close()

# note that "s" is now global instead of being passed through each function
# (this just makes it easier)
s = line[0]
N = int(line[1])

n = max(0, ceil(log2(N / len(s))))
C = f(n, N - 1)

# Output
fout = open("cowcode.out", "w")
fout.write(str(C) + "\n") # we need a newline after the answer
fout.close()
