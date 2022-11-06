from random import randint
from subprocess import run, PIPE

def gen_input():
  N = randint(1, 3)
  M = randint(1, 3)
  R = randint(1, 3)

  cows = [randint(1, 10) for i in range(N)]
  stores = [[randint(1, 10), randint(1, 200)] for i in range(M)]
  rentals = [randint(1, 200) for i in range(R)]

  newline = "\n"
  return (
    f"{str(N)} {str(M)} {str(R)}\n"
    f"{newline.join(map(str, cows))}\n"
    f"{newline.join([f'{str(a)} {str(b)}' for [a, b] in stores])}\n"
    f"{newline.join(map(str, rentals))}\n"
  )

def stress():
  generated = gen_input()
  my_solution = run(["./rental"], stdout=PIPE, input=generated, encoding="ascii")
  correct_solution = run(["./correct"], stdout=PIPE, input=generated, encoding="ascii")

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
