from random import randint, choice
from subprocess import run, PIPE

def gen_input():
  N = randint(1, 3)
  TC = randint(1, 5)
  TM = randint(1, 5)

  cows = []
  for i in range(N):
    a = randint(1, 5)
    b = randint(1, 5)

    cows.append(f"{a} {b} {randint(a + b, 10)}")
  
  newline = "\n"
  return f"{N} {TC} {TM}\n{newline.join(cows)}"


def stress():
  generated = gen_input()
  my_solution = run(["./bakery"], stdout=PIPE, input=generated, encoding="ascii")
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
