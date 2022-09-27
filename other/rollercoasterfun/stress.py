import random
from subprocess import run, PIPE

def gen_input():
  N = random.randint(1, 4)
  input = str(N) + "\n"
  for _ in range(N):
    input += str(random.randint(1, 10)) + " "
    input += str(random.randint(1, 10)) + " "
    input += str(random.randint(1, 10)) + "\n"
  
  Q = 100
  input += str(Q) + "\n"
  for i in range(1, Q + 1):
    input += str(i) + "\n"

  return input

def stress():
  generated = gen_input()
  my_solution = run(["./rollercoasterfun"], stdout=PIPE, input=generated, encoding="ascii")
  correct_solution = run(["./alex"], stdout=PIPE, input=generated, encoding="ascii")

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
