# USACO (and other CP) solutions
#### My previous CP repository (in Java) can be found [here](https://github.com/megargayu/USACO-Training).
This is where all of my competitive programming code resides! Most of this is for USACO, but other sites such as CodeForces and CSES are in here too. All solutions are in C++, but there are also Python files littered around (eg. for stress testing).

## *Please do not copy and paste the answers from this repo. This is only here for educational purposes, and you will not learn if you copy and paste from here.*

## Structure
**Note:** Some of these "solutions" might not work (because I was too lazy or forgot to implement them), so make sure to check if they make sense and if they produce the expected results on the grader when tested. In general, most problems should be solved to 100%, but whenever there is a `// TODO` comment or the code looks incomplete, it's probably not ready.
- `/contests` contains all of my solutions to USACO problems, and to find a certain problem, navigate like this: `/contests/{division}/{year}/{name}/{name}.cpp`. For contests after or during the 2020 December contest, since there is no problem name, `{name}` is made up based on the context of the full title of the problem. I also sometimes add multiple files for reiterations - the last one is usually correct. 
- `/cf` and `/cses` hold all codeforces and cses problems I have solved, respectively. These should have the URLs to the original problems at the top, and the names are made up for these as well.
- `/training` is for the USACO training website, and isn't sorted, just a list of problems.
- `/algos` contains a directory of algorithms I might use in the future.
- `/other` holds solutions to other problems which don't appear on these sites, such as from previous IOI contests.

## Development Environment
I use Ubuntu WSL2 with the GNU GCC compiler (`g++`) and Visual Studio Code with C++ support as well as [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner). My command for Code Runner looks like this, conforming to the command used by the USACO grader:
```json
"code-runner.executorMap": {
  "cpp": "cd $dir && g++ ./\"$fileNameWithoutExt.cpp\" -o \"$fileNameWithoutExt\" -O2 -std=c++17 -lm && ./\"$fileNameWithoutExt\""
},
```
