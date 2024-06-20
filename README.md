## <p align="center">Simple Shell </p>
 

#### <p align="center"> A UNIX COMMAND LINE INTERPRETER </p>
 
  
  > ![Tcsh_ejecutándose_en_escritorio_Mac_OSX](https://github.com/Anoonaa/simple_shell/assets/122968120/9fd93abc-a445-4e9a-9c7a-a247dd9ece73)

 
#### <p align="center"> INSTALL </p>
<p align="center">Set up the Simple Shell by following these steps: </p>

1. Clone the repository:
    ```sh
    git clone https://github.com/Anoonaa/simple_shell.git
    ```
2. Navigate to the project directory:
    ```sh
    cd simple_shell
    ```
3. Compile the source code:
    ```sh
    gcc -o simple_shell *.c
    ```
<p align="center"> Start the Simple Shell ! : </p>

```sh
./simple_shell
```
---
#### <p align="center"> List of Functions and System Calls </p>          
---                                                                      
-   `access` (man 2 access)                                              
-   `chdir` (man 2 chdir)                                                
-   `close` (man 2 close)                                                
-   `closedir` (man 3 closedir)                                          
-   `execve` (man 2 execve)                                              
-   `exit` (man 3 exit)                                                  
-   `_exit` (man 2 _exit)                                                
-   `fflush` (man 3 fflush)                                              
-   `fork` (man 2 fork)                                                  
-   `free` (man 3 free)                                                  
-   `getcwd` (man 3 getcwd)                                              
-   `getline` (man 3 getline)                                            
-   `getpid` (man 2 getpid)                                              
-   `isatty` (man 3 isatty)                                              
-   `kill` (man 2 kill)                                                  
-   `malloc` (man 3 malloc)                                              
-   `open` (man 2 open)                                                  
-   `opendir` (man 3 opendir)                                            
-   `perror` (man 3 perror)                                              
-   `read` (man 2 read)                                                  
-   `readdir` (man 3 readdir)                                            
-   `signal` (man 2 signal)                                              
-   `stat` (__xstat) (man 2 stat)                                        
-   `lstat` (__lxstat) (man 2 lstat)                                     
-   `fstat` (__fxstat) (man 2 fstat)                                     
-   `strtok` (man 3 strtok)                                              
-   `wait` (man 2 wait)                                                  
-   `waitpid` (man 2 waitpid)                                              
-   `wait3` (man 2 wait3)                                                
-   `wait4` (man 2 wait4)                                                
-   `write` (man 2 write)                                                
---
### General


This shell should work like this in `interactive mode`:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

```

But also in ` non-interactive mode`:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

```

### <p align="center"> AUTHOR</p>
> <p align="center"> Anoona Sithole </p>
