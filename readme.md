# Intro to C

## Hello World

This is what Hello World looks like in C:

```c
#include <stdio.h>

int main(){
    printf("Hello C!\n");
    return 0;
}
```

`#include <stdio.h>` imports part of the standard library. Most of the standard library is called std something. In this case we could read stdio as Standard Input/Output.

All programs must have a function called "main" at their root. The main function is where program execution begins. It begins with the keyword `int`, that's how we specify the return type of the function. By convention our main function should return a 0 to tell the OS our program exited gracefully and some other number to indicate that it failed.

`printf` is the function we imported from stdio. We'll talk about its use later but in the meantime know that it can print string literals.

You'll note that ending statements with a semicolon is mandatory in C. JS is the only language I know of where they are optional.

Now we've written the code let's run it.

## Using a Compiler

Not so fast! C is a compiled language. What that means is we have to use a program called a compiler to translate it from C to an executable program our OS knows how to run. There are a bunch of compilers out there but for this talk I'll be using GCC, the Gnu Compiler Collection.

The simplest way to use GCC is like so:

`gcc hello.c`

If we run that command the compiler will read our C source file and compile it into an executable called 'a'. We can then invoke a like so:

`./a` will print "Hello C!" to the console. Great!

### GCC Options

-o

-Wall -Wextra

### A Quick Foray Into Bash

```sh
#!bash
gcc -Wall -Wextra hello.c -o hello
```

## Arrays

Array literals are static. Dynamic arrays are a whole other thing.

```c
#include <stdio.h>

int main(){
    int nums[] = {3, 5, 6, 11, 2};
    for(int i = 0; i < 5; i++){
        printf("%i\n", nums[i]);
    }
    return 0;
}
```

## Data types

int, float, double, char, string, uint, stdint, NULL

void, kind of

no bools! kind of

## Functions

doubler

summer

greeter & string formatting

## Pointers

inc

double_all

## Structs

## simple macros and headers

include, define, headers, and header guards

## malloc, calloc, memcpy, and free

## Dynamic arrays

push, pop, print