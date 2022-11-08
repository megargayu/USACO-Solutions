from random import randint
from subprocess import run, PIPE

def gen_input():
  n = randint(1, 5)
  m = randint(n, 10)

  a = []; b = []
  for i in range(n):
    a.append(randint(1, 10))
  
  for i in range(m):
    b.append(randint(1, 10))
  
  return (
    f"{str(n)} {str(m)} 0\n"
    f"{' '.join(map(str, a))}\n"
    f"{' '.join(map(str, b))}\n"
  )

def stress():
  generated = gen_input()
  my_solution = run(["./mohamoudehabfunc"], stdout=PIPE, input=generated, encoding="ascii")
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
