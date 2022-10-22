import random
from random import randint
from subprocess import run, PIPE

def gen_input():
  N = randint(1, 10)
  values = set()
  result = f"{N}\n"
  for i in range(N):
    while True:
      a = randint(1, 100)
      b = randint(1, 100)
      if a != b and (a, b) not in values: break
    values.add((a, b))
    result += f"{a} {b}\n"
  return result

def stress():
  generated = gen_input()
  my_solution = run(["./mountains"], stdout=PIPE, input=generated, encoding="ascii")
  correct_solution = run(["./brute"], stdout=PIPE, input=generated, encoding="ascii")

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
