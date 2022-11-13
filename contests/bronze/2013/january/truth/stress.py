from random import randint
from subprocess import run, PIPE

def gen_input():
  N = randint(2, 1000)
  M = randint(1, N)
  
  seen = set()
  vals = []

  for i in range(M):
    while True:
      a = randint(1, N)
      b = randint(1, N)
      if a != b and (a, b) not in seen:
        seen.add((a, b))
        break
    
    vals.append(f"{str(a)} {str(b)} {'L' if randint(0, 1) == 0 else 'T'}")
  
  newline = '\n'
  return (
    f"{N} {M}\n"
    f"{newline.join(vals)}\n"
  )

def stress():
  generated = gen_input()
  my_solution = run(["./truth2"], stdout=PIPE, input=generated, encoding="ascii")
  correct_solution = run(["./truth"], stdout=PIPE, input=generated, encoding="ascii")

  if my_solution.stdout != correct_solution.stdout:
    with open("input.in", "w") as fin:
      fin.write(generated)

    with open("correct.out", "w") as fout:
      fout.write(correct_solution.stdout)

    with open("incorrect.out", "w") as fout:
      fout.write(my_solution.stdout)
    
    return False
  
  return True


i = 1
while True:
  result = stress()
  if result:
    print(f"Success on test case {i}")
  else:
    print(f"Found wrong test case ({i})!")
    break

  i += 1
