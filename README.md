**BSQ:** 
## ***A 42 project... :***
[Subject][1]
## Requirement:
You must be on a Linux distribution or macOS.
## Usage:
Launch make in the repository and than use the following command to create a map : ./tableau.sh x y z > map.txt
x = number of row in the x axe
y = number of row in the y axe
z = density of obstacle
For example, the command :"./tableau.sh 100 100 10 > map.txt" will create a map of 100x100 with a density of 10.
Now that you have your map, you can use the program BSQ to find the biggest square drawable in the map:
./BSQ map.txt

`Example:`

![test_image](minishell_test.png)

## Goal:

- [x] No memory leaks
- [x] Norm

The goal of this project is to make a program which is able to find the biggest square possible in a map without going through any obstacles.

- Execute all bash command
- Prompt printing
- Use redirection ***"<" "<<" ">"***
- Pipe "|"
- colons ";"
- " and ' (You should not be able to handle open quote)
- $? (exit value)
- Environnement variable `Exemple: export date=2021 ; echo $date`
- Environnement variable like `SHLVL`, `PWD`, `OLDPWD` must be updated when necessary
- The following signal must be handled like bash :

|  Ctrl-C       |       Ctrl-\     |      Ctrl-D    |
| -------------- | --------------- | -------------- |
| Send SINGINT   | Send SIGQUIT    | Send EOF       | 

- The following builtin **_MUST_** be implemented by yourself :

|  echo          |       cd        |      pwd       |    export      | unset          | env            | exit           |
| -------------- | --------------- | -------------- | -------------- | -------------- | -------------- | -------------- |
| With -n option | With no option  | With no option | With no option | With no option | With no option | With no option |

## Final grade:
100/100

### Nota bene:
I didnt do termcaps and history gestion with up and down arrow.


[1]: https://github.com/fleger42/minishell_liste/blob/master/minishell_pdf.pdf
[2]: https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html
