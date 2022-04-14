from random import randint, choice
from subprocess import call

def gen():
  N = randint(3, 10)
  M = randint(1, (N * (N - 1)) / 2)

  print(f"N = {N}, M = {M}...", end=" ")
  data = f"{N} {M}"
  connections = [[False for x in range(N)] for y in range(N)]
  for _ in range(M):
    a = randint(1, N)
    b = randint(1, N)
    while a == b:
      b = randint(1, N)
    
    while connections[a - 1][b - 1] or connections[b - 1][a - 1]:
      a = randint(1, N)
      b = randint(1, N)
      while a == b:
        b = randint(1, N)
  
  
    connections[a - 1][b - 1] = True
    connections[b - 1][a - 1] = True
    
    data += f"\n{choice(('S', 'D'))} {a} {b}"

  with open("revegetate.in", "w") as fin:
    fin.write(data + "\n")
  
  return data

my_sol = ""
accepted = ""
for i in range(100):
  gen()
  print(f"Running test {i + 1}...", end=" ")

  call(["wsl", "./revegetate"])
  with open("revegetate.out", "r") as out:
    my_sol = out.read()
  
  call(["wsl", "./solution"])
  with open("revegetate.out", "r") as out:
    accepted = out.read()
  
  if my_sol != accepted:
    print("FOUND FAULTY CASE! Bad solution in broken.out, correct solution in revegetate.out")
    with open("broken.out", "w") as broken:
      broken.write(my_sol)
    break
  
  print(f"Correct!")
