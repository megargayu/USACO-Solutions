from random import randint, choice
from subprocess import run, PIPE
from string import ascii_letters

def gen_input():
  def get_rand(len):
    return "".join(choice(ascii_letters) for _ in range(len))

  N = randint(1, 3)
  testcases = []
  for i in range(N):
    length = randint(1, 5)
    testcases.append(f"{get_rand(length)}\n{get_rand(length)}")
  newline = "\n"
  return f"{N}\n{newline.join(testcases)}\n"


def stress():
  generated = gen_input()
  my_solution = run(["./findrepl3"], stdout=PIPE, input=generated, encoding="ascii")
  correct_solution = run(["python", "solution.py"], stdout=PIPE, input=generated, encoding="ascii")

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
