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
<!-- Updated: 2022/11/05 14:09:25 by aperez-b                                -->
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
	- [3.1](#31)
	- [3.2](#32)
	- [3.3](#33)
- [Summary](#summary)

## Introduction

This practice proposes a series of activities with the aim the student can apply on
a Unix system some of the concepts introduced in the subject.
The student will have to do experiments and answer the proposed questions. You
will also need to write a short program in *C* language.
The practice can be developed on any *UNIX* system (the *UOC* facilitates **Ubuntu
14.04** distribution). It’s recommended that while you are doing the experiments
there are no other users working on the system because the result of some
experiments may depend on the system load.

I will personally develop this practical activity from **Fedora Workstation 37** and **ArchLinux**.

### Base Code

For the following questions, some code has been provided. It is all included in the ``pr1so/`` folder. Here is a brief description of what *some* of the files do:

- **``count1.c``** executes an infinite loop where each iteration increments a counter (initialized to ``0``). When count1 receives the asynchronous notification indicating that it must end, it prints the counter value and ends. ``count1.c`` emulates an intensive computational process.

- **``count2.c``** executes an infinite loop where each iteration increase a counter (initialized to ``0``) and waits a millisecond (blocking) before iterating again. When ``count2`` receives an asynchronous notification indicating that it should end, it prints the counter value and ends. ``count2.c`` emulates an interactive process.

- **``launch.sh``** starts the concurrent execution of ``N`` processes running the ``count1`` program and another ``N`` running the ``count2`` (``N`` is the first parameter of the shellscript). By default, once 3 seconds have elapsed, it terminates all count processes. If we want the execution time to take a different amount of time, the shellscript supports a second optional parameter that indicates the desired execution time.

## Question 1. Processes

### 1.1. Count Programs Study

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

🚧

**Question**

How many cores are you actually using? This number may be different from that obtained in 1.2.2. depending on how the operating system is set up, the virtual machine (in case you are using one) or if you have Hyperthreading enabled. To answer this question, count how many lines the following command is typed in and attach a screenshot of the result.

```shell
grep processor /proc/cpuinfo
```

If the result is less than the number you obtained in 1.2.2., Reconfigure your system/virtual machine to ensure that the number of kernels you use is at least equal to the number of kernels available. Please indicate how you reconfigured the system and show the result of ``grep processor /proc/cpuinfo`` again.

**Answer**

🚧

### 1.3. Running the Script

**Question**

Run the ``launch.sh`` script several times, changing the value of the parameter from 1 to twice the value you tested in section 1.2.3. Explain the trend of the counters that print the processes ``count1`` (the first ``N`` counters shown) as you increase the value of the parameter and relate it to the answers 1.2.2. and 1.2.3. Show screenshots of executions.

**Answer**

🚧

**Question**

Do the numbers that print the ``count2`` processes (the last ``N`` counters shown) follow the same trend? Justify the answer.

**Answer**

🚧

### 1.4. Execution of the top Command

**Question**

From another window, run the ``top`` command, which shows information about *CPU* usage and which processes are consuming the most. From the original window, run ``./launch.sh 1 20`` and look at the information that shows top while launching. What can you conclude?

**Answer**

🚧

## Question 2. Memory

We provide you with the ``stack.c`` program which supports a numeric parameter (``1``, ``2``, ``3``, ``4``, ``5`` or ``6``). Study its source code, compile it, and run it. When running it on your system, the sequence of numbers generated in each case may be different (longer or shorter) than the examples; However, in all cases, the operating system must abort the program (the message Segmentation fault is displayed).

### 2.1. Stack

**Question**

In all cases, the program ends up with invalid memory access and the operating system aborts the process. Indicate justifiably at which point in the program this invalid access is caused in each case.

**Answer**

🚧

**Question**

What’s the cause of the time that the program takes to abort is different in each case? What does it depend on?

**Answer**

🚧

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

The code can be found in the file ``main.c``, here is a screenshot proving it works:

🚧

## Question 3. In and Out

The ``args.c`` program shows the list of parameters it receives on the command line.

Several examples of execution are attached:

![args Executable](https://user-images.githubusercontent.com/40824677/200119958-706e56cf-e2ea-4ffb-a830-48d0690f2537.jpg)

### 3.1

**Question**

How is it that in the third example `argc` has the value 3 and not 5?

**Answer**

The correct number of arguments (`argc`) is 3 and not 5 because the command-line interpreter reads the pipe symbol `|` as a special character that, in this case, pipes the output of the command to the left of the pipe to the `stdin` of the command to the right of the pipe. Thus, the only things passed as arguments to the executable `arg` are `a1` and `a2` before the special character appears.

### 3.2

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

### 3.3

**Question**

Replace the two occurrences of ``stderr`` with ``stdout`` in ``args.c``. Compile the program and run the third example again. Explain what the new observed behavior is due to.


**Answer**

Code to replace occurrences of `stderr`:

```shell
sed -i 's/stderr/stdout/g pr1so/args.c'
```

New output of third example:

```shell
pixel@minishell:~$ ./args a1 a2 | wc
      4       6      52
pixel@minishell:~$
```

This happends because pipes (`|`) will take the standard output (`stdout`) *only* and use it as standard input (`stdin`) for the command that follows the pipe. Initially the code printed on the standard error (`stderr`), which is usually used, as the name suggests, for printing error messages. Messages printed on the `stderr` will be displayed on the console but **will not be piped onto the next command**. That is why when printing on the `stdout` instead of on the `stderr`, the entire output of our `args` command is passed onto the `wc` command. This second command counts words, lines and characters from the standard input (`stdin`) or from a file (see `man wc`). That explains the three zeroes from example 3 when using `stderr`, as nothing was being passed as input.

## Summary

🚧

November 5th, 2022
