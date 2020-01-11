# minishell
The goal of the project is to create a mini-shell capable of reading and evaluating simple user commands

The executable file `./minishell` is a mini UNIX command interpreter. 

The program manages:
* a series of builtins: `echo`, `cd`, `setenv`, `unsetenv`, `env`, `exit`
* the expansions `$` and ` ̃`
* the separation of commands with `;`
* quotes `'` and double quotes `"`

```
> make
> ./minishell
 ```
