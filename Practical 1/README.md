<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                         =@@*   +@@+                     -->
<!--                                         =@@*   +@@+ :*%@@@%*:           -->
<!--                                         =@@*   =@@+.@@@=--%@@-          -->
<!--                                         :@@%. .#@@--@@*   +@@* .+%@@@   -->
<!-- README.md                                =%@@@@@@+ =@@*   =@@+.@@@+-=   -->
<!--                                            .---:   -@@#.  *@@--@@*      -->
<!-- By: aperez-b <aperez-b@uoc.edu>                     +@@@@@@@* +@@+      -->
<!--                                                       :-==:.  -@@#      -->
<!-- Created: 2022/11/05 13:26:51 by aperez-b                       +@@@%@   -->
<!-- Updated: 2022/11/11 22:17:15 by aperez-b                                -->
<!--                                                                         -->
<!-- *********************************************************************** -->

# Practical 1

### Table Of Contents

- [Introduction](#introduction)
- [Question 1. Processes](#question-1-processes)
	- [1.1. Count Programs Study](#11-count-programs-study)
	- [1.2. Hardware Analysis](#12-hardware-analysis)
	- [1.3. Running the Script](#13-running-the-script)
	- [1.4. Execution of the top Command](#14-execution-of-the-top-command)
- [Question 2. Memory](#question-2-memory)
	- [2.1. Stack](#21-stack)
	- [2.2. Code Exercise](#22-code-exercise)
- [Question 3. In and Out](#question-3-in-and-out)
- [Summary](#summary)

## Introduction

This practice proposes a series of activities with the aim the student can apply on a U system some of the concepts introduced in the subject. The student will have to do experiments and answer the proposed questions. You will also need to write a short program in *C* language. The practice can be developed on any *UNIX* system (the *UOC* facilitates **Ubuntu 14.04** distribution). It’s recommended that while you are doing the experiments there are no other users working on the system because the result of some experiments may depend on the system load.

I will personally develop this practical activity from **Fedora Workstation 37** and **ArchLinux**.

### Base Code

For the following questions, some code has been provided. It is all included in the ``pr1so/`` folder. Here is a brief description of what *some* of the files do:

- **``count1.c``** executes an infinite loop where each iteration increments a counter (initialized to ``0``). When count1 receives the asynchronous notification indicating that it must end, it prints the counter value and ends. ``count1.c`` emulates an intensive computational process.

- **``count2.c``** executes an infinite loop where each iteration increase a counter (initialized to ``0``) and waits a millisecond (blocking) before iterating again. When ``count2`` receives an asynchronous notification indicating that it should end, it prints the counter value and ends. ``count2.c`` emulates an interactive process.

- **``launch.sh``** starts the concurrent execution of ``N`` processes running the ``count1`` program and another ``N`` running the ``count2`` (``N`` is the first parameter of the shellscript). By default, once 3 seconds have elapsed, it terminates all count processes. If we want the execution time to take a different amount of time, the shellscript supports a second optional parameter that indicates the desired execution time.

## Question 1. Processes

### 1.1. Count Programs Study

**Question**

Once studied the behavior of `count1`, draw a graph of states with three nodes (one for each possible state of the process: **Ready**, **Run** and **Wait**) and with the arcs that reflect the state changes which can occur while a process is running `count1`.

**Answer**

![Graph for count1](https://user-images.githubusercontent.com/40824677/201429284-e6f1d053-f751-4629-9772-b082ee5fa743.png)

**Question**

Similar to 1.1.1., draw the graph showing the state changes that a process running `count2` may happen.

**Answer**

![Graph for count2](https://user-images.githubusercontent.com/40824677/201429282-4fc01180-c31c-459b-8437-33c52e6a1974.png)

### 1.2. Hardware Analysis

**Question**

Please indicate which specific processor model you are working on.

**Answer**

```shell
pixel@minishell ~ $ grep 'model name' /proc/cpuinfo | head -1
model name	: Intel(R) Core(TM) i5-8259U CPU @ 2.30GHz
pixel@minishell ~ $ 
```

**Question**

How many physical cores (cores) does your processor have? If your processor is Intel, you may want to check out [Intel Ark](http://ark.intel.com/).

**Answer**

My device has `8` **logical cores** resulting from `4` **cores** each with `2` **threads**. In other words,

```
(4 physical cores) x (2 threads per core) = 8 logical cores
```

My device has **Hyperthreading** capabilities, it takes advantage of up to `8` cores running at the same time.

**Question**

How many cores are you actually using? This number may be different from that obtained in 1.2.2. depending on how the operating system is set up, the virtual machine (in case you are using one) or if you have Hyperthreading enabled. To answer this question, count how many lines the following command is typed in and attach a screenshot of the result.

```shell
grep processor /proc/cpuinfo
```

If the result is less than the number you obtained in 1.2.2., Reconfigure your system/virtual machine to ensure that the number of kernels you use is at least equal to the number of kernels available. Please indicate how you reconfigured the system and show the result of ``grep processor /proc/cpuinfo`` again.

**Answer**

Screenshot of the command output:

!["grep processor /proc/cpuinfo" command](https://user-images.githubusercontent.com/40824677/200289181-09d5805c-beb3-41c5-b867-6e4ce706a0e2.png)

I have 8 processors resulting from the aforementioned **Hyperthreading**.

### 1.3. Running the Script

**Question**

Run the ``launch.sh`` script several times, changing the value of the parameter from 1 to twice the value you tested in section 1.2.3. Explain the trend of the counters that print the processes ``count1`` (the first ``N`` counters shown) as you increase the value of the parameter and relate it to the answers 1.2.2. and 1.2.3. Show screenshots of executions.

**Answer**

There is a clear trend: the more concurrent executions of the program are created, the more system load is created and thus thus the program `count1` can count up to a smaller number. My device has `8` **threads** in the `4` **physical** cores of the CPU. Depending on the scheduler of the CPU and my personal system configurations, some processes may be prioritized over other ones. Therefore it is very hard to find one clear trend in the executions. Perhaps it is interesting to evaluate what happens when we launch more threads than there are *actual* threads (i.e. CPU cores). Computers can launch many threads at once, certainly many more than `8`. Ideally, every thread would be assigned some core, but in reality is not handled in this way; the process and its threads might switch between different cores during execution, again, related to the scheduler and the specifics of every system.

Screenshot of outputs from `1` to `2N` (`N` being the number of processors on my system).

![./stack 1](https://user-images.githubusercontent.com/40824677/201409561-3600dfbf-76a5-4f2b-9bba-7aeb9337a43b.png)
![./stack 2](https://user-images.githubusercontent.com/40824677/201409558-6d6fc2bc-418f-4ed6-a6ad-115f6871d06f.png)

![./stack 3](https://user-images.githubusercontent.com/40824677/201409554-38101436-f36b-41ee-9af6-d7067e5bf2cb.png)
![./stack 4](https://user-images.githubusercontent.com/40824677/201409550-d62ca280-af5a-4765-9bb5-16ce18e43be7.png)

![./stack 5](https://user-images.githubusercontent.com/40824677/201409547-94cc32e1-19e9-4c2d-a010-f7cb5b1c392e.png)
![./stack 6](https://user-images.githubusercontent.com/40824677/201409546-5a63a517-6ce4-42e5-9b11-a6906199d65a.png)

![./stack 7](https://user-images.githubusercontent.com/40824677/201409540-06dc06fc-4908-4572-aa04-08cc7222f7f1.png)
![./stack 8](https://user-images.githubusercontent.com/40824677/201409538-afcef3c4-a0ed-4acb-9c5a-116134d857a0.png)

![./stack 9](https://user-images.githubusercontent.com/40824677/201409534-96c3c111-a4f3-4b8c-a42e-8c35ad01a52a.png)
![./stack 10](https://user-images.githubusercontent.com/40824677/201409532-d4f7cef8-257b-4c0c-b8dc-eea43c6bc7c2.png)

![./stack 11](https://user-images.githubusercontent.com/40824677/201409530-9e2978a5-27c6-4309-90ce-b06a21d8f4fe.png)
![./stack 12](https://user-images.githubusercontent.com/40824677/201409528-9160c8a7-1275-4351-854d-e9f6accb0dfe.png)

![./stack 13](https://user-images.githubusercontent.com/40824677/201409525-c1983831-950d-404d-83e7-198b69a9fa40.png)
![./stack 14](https://user-images.githubusercontent.com/40824677/201409523-79e3692d-c6b0-499a-ad0f-a7900b1452c7.png)

![./stack 15](https://user-images.githubusercontent.com/40824677/201409518-504f6cbb-f0b7-4e08-923c-a969a6e7f8ed.png)
![./stack 16](https://user-images.githubusercontent.com/40824677/201409512-4a021aab-65e4-400d-bed0-c6abc4aff90b.png)

*These results are taken after several repetitions of the same command, to show the general output. These results vary a lot depending on the system usage and other running applications, as well as depending on how fast the computer is.*

**Question**

Do the numbers that print the ``count2`` processes (the last ``N`` counters shown) follow the same trend? Justify the answer.

**Answer**


The output values for the `count2` command do not vary in any significant way, giving consistent values of around `3700`. This is because the constraint that keeps this value low is the `usleep` call of `1000ms`, and not so much the fact that the system is running many processes simultaneously. As we saw with the `count1` program, which had no constraint and the counter had no slowdowns, the system can count numbers far greater than `1600000000` in some circumstances. The **bottleneck** for `count2` is the delay before every iteration, rather than the number of running processes.

### 1.4. Execution of the top Command

**Question**

From another window, run the ``top`` command, which shows information about *CPU* usage and which processes are consuming the most. From the original window, run ``./launch.sh 1 20`` and look at the information that shows top while launching. What can you conclude?

**Answer**

By default, the `top` command lists the running processes on the system, with the most CPU-intensive processes on the 'top' of the list. `count1` appears on the very beginning because it is supposed to emulate a heavy task using tons of system resources. `count2` on the other hand is much less CPU-intensive because of the delay introduced before counting and thus does not appear on top of the list. This does not mean that the processes are not createds or that they do not show up on the `top` command, it merely shows the `count2` processes much lower on the list, not visible at a glance at the command.

Screenshot of the `top` command during execution of `./stack 16`.

![Example top command with ./stack 16](https://user-images.githubusercontent.com/40824677/201414180-4a0e9f53-f46e-4cf6-a848-986de9c0b604.png)


## Question 2. Memory

We provide you with the ``stack.c`` program which supports a numeric parameter (``1``, ``2``, ``3``, ``4``, ``5`` or ``6``). Study its source code, compile it, and run it. When running it on your system, the sequence of numbers generated in each case may be different (longer or shorter) than the examples; However, in all cases, the operating system must abort the program (the message Segmentation fault is displayed).

### 2.1. Stack

**Question**

In all cases, the program ends up with invalid memory access and the operating system aborts the process. Indicate justifiably at which point in the program this invalid access is caused in each case.

**Answer**

Here are the reasons why the program (`rec1`, `rec2`, ..., `rec6`) crashes with a segmentation faults occur.

- **`rec1`**: Reaches a stack overflow somewhere in between `52000` and `53000` recursions. That's why the program lists `52` right before crashing, which happens when the stack size is filled due to the endless amount of recursive calls.
- **`rec2`**: In this case an *int pointer* is initialized with `128` bytes of memory of reserved **on the heap** with `malloc`. In this case the stack overflow occurs sooner than before because the function calls and variable initializations are done **on the stack** of the program.
- **`rec3`**: This case is almost the same as the last one, but `malloc` reserves `256` bytes of memory. Executables run with a set of stack (static) memory and heap (dynamic) memory. Memory on the heap can exceed and start using resources as needed, while stack memory will only allow for so much memory. That is why after increasing stack memory beyond a certain limit on this recursive function, the program aborts. In summary, this example is no different from before because in both cases the real cause of the stack overflow is the initialization of the `int *` variable and the recursive function call, allocating more or less with dynamic memory has little impact on the abort result. In fact, if you just leave the pointer declaration and remove the `malloc` call (initializing the pointer to `NULL`), the abort sticll happens after printing `26`.
- **`rec4`**: In this case we are declaring an array of `16` `int` variables, which are all allocated on the stack (including the pointer declaration). This causes the program to (once again) overflow, but way faster than before since there are many more variables on the stack than before, and because the function keeps calling itself again and again it never has time to destroy those variables allocated on the stack, making it larger and larger till it grows to its limit (the limit defined by the current heap memory, growing in the opposite direction of the stack).
- **`rec5`**: this time we are allocating an array of `32` integers. Previously the program crashed right after printing `8` on the console, and this time the program crashes after printing `5`. It does not exactly take half the time to crash (that would be printing `4` on the console), because previously we had `16` integers from the array, plus the pointer to the array. This time we are just allocating an extra `16` integers, thus causing the crash to occur almost (but not quite) half as fast as before.
- **`rec6`**: this time the crash occurs before the first `1000` recursions (that would be the equivalent of printing `1` in the previous functions), the fastest of all the `rec` functions. In each recursive call we are assigning a new value of a **global int array** of 1500 ints. The program crashes after printing the `2000`th iteration, however at some point we see that the program accesses indexes out of bounds of the array (indexes over `1500`). This is defined to have an undefined behavior, but not necessarily a crash, which explains how the program didn't crash and successfully printed `1600`, `1800` and `2000`. Having this in mind, the program aborts when it tries to access memory outside the bounds of the program.

**Question**

What’s the cause of the time that the program takes to abort is different in each case? What does it depend on?

**Answer**

Generally, every case has a similar reason for aborting. As I previously mentioned, programs run with a predefined amount of memory and resources to run, with the possibility to dynamically ask the operating system for extra resources the stack and heap memory grow towards one another. Function calls and variable definitions inside them are stored on the stack and freed after the function finishes execution. On the previous examples we saw various cases of stack overflows due to infinite recursions, and the main factor determining how quickly the segmentation faults occurred was the number of variable declarations and initializations inside the recursive call. It is only because of the nature of recursivity that these issues occur, because every time we call the function we allocate on the stack all the local variables in it. In the last case, however, the segmentation fault happens not because of the variable declarations (there aren't any), but rather because we are endlessly accessing and modifying the value of a finite array, so at some point we will try to access points beyond the scope of the array, eventually causing a segmentation fault for trying to access memory outside the memory granted to the running file.

### 2.2. Code Exercise

**Question**

Type a program that reads keyboard strings until it detects that the same string has been entered twice. To implement this, you need to use dynamic memory management routines.

Your solution should store strings in a list where each item in the list will store the contents of one string and a pointer in the next item in the list. The list will grow dynamically as you read strings. To check if a string has already been read, you'll need to go through all the positions in the list and see if it already exists.

As a guide, we provide you with the structure of a possible solution (``mem3_base.c``). You can use it as a reference and implement the missing code.

You must provide the source code of the program and, if it works, a screenshot to prove it.

Some remarks on the code to implement:

- This is not the most efficient solution to this problem, but it is the solution we ask you to implement.
- The number of strings to read until a repeat is detected can be arbitrarily large.
- You can assume that the maximum size of each string will be ``80`` characters.
- The memory must be freed before the program can run dynamics that have been requested.
- To compare strings you must use the ``strcmp()`` routine.

**Answer**

The code can be found in the file ``main.c``

To compile the code, you can run the following command in the appropriate directory:

```shell
gcc -Wall -Wextra -Werror main.c -o mem3
```
Note: The compilation flags `-Wall -Wextra -Werror` are optional, used to optimize the code and avoid having unused variables.

To run the code, you can simply run the following command:

```shell
./mem3
```

Here are some screenshots proving it works:

![mem3 executable example](https://user-images.githubusercontent.com/40824677/200535430-85c0091e-a083-44ea-a4eb-2893ba2e7224.png)

![mem3 executable example](https://user-images.githubusercontent.com/40824677/200534463-1a9b951d-dfb7-4acf-b8d6-a864144c6a9e.png)

![mem3 executable example](https://user-images.githubusercontent.com/40824677/200534449-a7b82095-3756-433a-891b-8436bea4bcc6.png)

*Note how this third example is run with **valgrind**, a tool that helps check for code errors and leaks. No errors are reported, so we assume that there are **no memory leaks**.*

As an added bonus, the code I created passes the so-called [`norminette`](https://github.com/42School/norminette), a linter for `.c` and `.h` files I use to keep code clean.

![norminette passed](https://user-images.githubusercontent.com/40824677/201417740-896d222c-e111-4d92-997e-10e00db2622a.png)

## Question 3. In and Out

The ``args.c`` program shows the list of parameters it receives on the command line.

Several examples of execution are attached:

![args Executable](https://user-images.githubusercontent.com/40824677/200119958-706e56cf-e2ea-4ffb-a830-48d0690f2537.jpg)

**Question**

How is it that in the third example `argc` has the value 3 and not 5?

**Answer**

The correct number of arguments (`argc`) is 3 and not 5 because the command-line interpreter reads the pipe symbol `|` as a special character that, in this case, pipes the output of the command to the left of the pipe to the `stdin` of the command to the right of the pipe. Thus, the only things passed as arguments to the executable `arg` are `a1` and `a2` before the special character appears.

**Question**

How is it that in the fourth example `argc` has the value 4 and not 2?

**Answer**

The number of arguments is 4 and not two in this case because the command-line interpreter (shell) treats the star symbol `*` as a special character. This symbol expands the command-line arguments with new entries that match the expression. In the example the wildcard will look for any occurrence of `/bin/ls` where anything can appear between `l` and `s` (or nothing at all). In the screenshot we can see that the user that ran the command only had three files (command binaries) that matched what the wildcard was looking for, namely:

```
/bin/less
/bin/loadkeys
/bin/ls
```

Thus, the shell internally expanded the wildcard to the said matches, effectively increasing the number of arguments passed to the `args` executable, as follows:

```shell
./args /bin/less /bin/loadkeys /bin/ls
```

**Question**

Replace the two occurrences of ``stderr`` with ``stdout`` in ``args.c``. Compile the program and run the third example again. Explain what the new observed behavior is due to.


**Answer**

Code to replace occurrences of `stderr`:

```shell
sed -i 's/stderr/stdout/g pr1so/args.c'
```

New output of third example:

```shell
pixel@minishell ~ $ ./args a1 a2 | wc
      4       6      52
pixel@minishell ~ $
```

This happends because pipes (`|`) will take the standard output (`stdout`) *only* and use it as standard input (`stdin`) for the command that follows the pipe. Initially the code printed on the standard error (`stderr`), which is usually used, as the name suggests, for printing error messages. Messages printed on the `stderr` will be displayed on the console but **will not be piped onto the next command**. That is why when printing on the `stdout` instead of on the `stderr`, the entire output of our `args` command is passed onto the `wc` command. This second command counts words, lines and characters from the standard input (`stdin`) or from a file (see `man wc`). That explains the three zeroes from example 3 when using `stderr`, as nothing was being passed as input.

## Summary

All in all, this first practical was much more challenging than expected, and it helped clarify many aspects about Operating Systems I previously ignored.

November 5th, 2022
