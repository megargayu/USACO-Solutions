from random import randint, choice
from subprocess import run, PIPE

def gen_input():
  N = randint(1, 100)
  rows = []

  for r in range(N):
    rows.append([choice(['D', 'R']) for c in range(N)] + [str(randint(1, 10))])
  rows.append([str(randint(1, 10)) for c in range(N)])

  Q = randint(1, 1)
  qs = []
  for i in range(Q):
    qs.append(f"{randint(1, N)} {randint(1, N)}")
  
  newline = "\n"

  return f"""{N}
{newline.join([' '.join(row) for row in rows])}
{Q}
{newline.join(qs)}
"""

def stress():
  generated = gen_input()
  my_solution = run(["./dirs2"], stdout=PIPE, stderr=PIPE, input=generated, encoding="ascii")
  correct_solution = run(["./brute"], stdout=PIPE, stderr=PIPE, input=generated, encoding="ascii")

  if len(my_solution.stderr) > 0:
    return False

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
