from random import randint
from subprocess import run, PIPE

def gen_input():
  n = randint(1, 10)
  x = randint(1, 100)
  vals = [str(randint(1, 100)) for _ in range(n)]
  
  return f"{n} {x}\n{' '.join(vals)}\n"

def stress():
  generated = gen_input()
  my_solution = run(["./sum3val"], stdout=PIPE, input=generated, encoding="ascii")
  correct_solution = run(["./brute"], stdout=PIPE, input=generated, encoding="ascii")

  print(my_solution.stdout.split(" "), correct_solution.stdout.split(" "))
  correct = (my_solution.stdout == correct_solution.stdout == "IMPOSSIBLE") or \
              (set(map(str.strip, my_solution.stdout.split(" "))) == 
               set(map(str.strip, correct_solution.stdout.split(" "))))

  if not correct:
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
