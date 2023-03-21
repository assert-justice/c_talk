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

If we run that command the compiler will read our C source file and compile it into an executable. I'm running GNU/Linux so that executable will be called 'a.out' for me. If you're on Windows executables end with the `.exe` file extension. We can then invoke the program like so:

`./a.out` will print "Hello C!" to the console. Great!

### GCC Options

gcc has a lot of options. Like, a lot of options. We are barely going to scratch the surface.

Typically we want to be able to control the name of the executable gcc emits. We do that with the `-o` command like so:

`gcc hello.c -o hello.out`

If we run the above command it should output a `hello.out` executable that we can run.

The only other options we're using for the lesson today concern warnings. We want to make gcc as pedantic as possible because C allows very unsafe behavior even with those warnings in place. We're going to look at some of that unsafe behavior later. For now we can enable all the warnings with the `-Wall` and `-Wextra` options like so.

`gcc -Wall -Wextra hello.c -o hello.out`

If we run the above command it *shouldn't* whine at us for a simple hello world example. Don't worry it'll whine plenty later.

### A Quick Foray Into Bash

As the commands we use to build and run C programs get more complex it becomes impractical to type the build command in the command line. There are a lot of solutions to this like make, cmake, and a whole bunch of other build tools but one of the simplest options is to use bash.

We've actually been using bash this whole time but specifically we'll write a bash script we can run on command. Bash is a whole programming language and again we're only scratching the surface here. Let's create a file called `build.sh` with the following:

```sh
#!bash
gcc -Wall -Wextra hello.c -o hello
```

The first line `#!bash` tells the OS which bash interpreter we want to use. The `#!` specifically is called a "shebang". Wikipedia tells me there are some alternative names for it, each sillier than the last. 

- sharp-exclamation, for incredibly tedious people
- sha-bang, a minor variant
- hashbang, getting saucy
- pound-bang, oh my
- hash-pling, sure that's an option

Shebang is standard though. If you go around calling it "pound-bang" you're gonna get some looks.

So we can run the above bash script like so:

`bash ./build.sh`

It will build our program and we can then run it as before.

It's common enough that you will want to build and then run immediately. Let's write another bash script to do that! We'll call it `run.sh`:

```sh
#!bash
bash build.sh && ./hello.out
```

What this one says is run the build script and if it succeeds execute the newly built program. If it fails do not. The '&&' is a way of chaining commands together such that if one of them fails no more are run.

Enough bashing our head in, let's move on.

## Variables and Data types

C has a number of data types that will be different from what you're used to coming from JS. We're going to spend the most time talking about integers.

Here's an example:

```c
#include <stdio.h>

int main(){
    int a = 5;
    int b = 10;
    int c = a + b;
    b = 20;
    printf("%i\n", c);
    return 0;
}
```

Couple of differences from JS already. Instead of using keywords like `let` or `var` or `const` to create variables we use the type that the variable is going to be, in this case `int`.

We create a variable `a` and set it to `5`, another called `b` and set it to `10`, another called `c` set to the sum of `a` and `b`, change the value of `b` to `20` (note that we don't specify the type of `b` when reassigning it), and finally use `printf` to print the value of `c`.

We'll talk more about what's going on in `printf` in a sec but you should be able to guess what the program will print.

It'll print `15`!. If you guessed `25` that's reasonable but remember `c` is set to the sum of `a` and `b` once, it is not update when the value of `b` is changed.

Ok what's going on with `printf`? Whats with `%i`? Well you know how we can do string template literals in JS, something like

```js
let a = 5;
let b = 10;
let c = a + b;
b = 20;
console.log(`${c}`);
```

Well `printf("%i\n", c);` is what we have in C. `%i` is how we tell the compiler we want to print an integer in that part of the string. Don't forget the trailing newline!

That `%i` is called a format specifier and there are a whole bunch of them in C, for printing all sorts of numbers, characters, strings, pointers, and what have you. Frankly, dealing with strings in C is a real pain in the butt and I'm not going to touch on it much in this talk but we will see some of those format specifiers come up.

Integers are whole numbers. On most modern operating systems an `int` is specifically an unsigned `32` bit integer. What the heck does that mean?

I could do a whole talk about binary and how numbers are represented. This is going to be the short version.

> I'm going to skip this bit for the talk.

Let's talk about decimals.

Consider a number with four decimal digits such as `1337`.

|10^3|10^2|10^1|10^0|
|---|---|---|---|
|1|3|3|7|

We use a positional number system where a digit's position in the number indicates what power of ten it should be multiplied by. Most of us haven't thought about this in a long while but what `1337` means is the number `1 * 1000 + 3 * 100 + 3 * 10 + 7 * 1`;

Let's look at a four digit binary number `1011`.

|2^3|2^2|2^1|2^0|
|---|---|---|---|
|1|0|1|1|

We would read this as `1 * 8 + 0 * 4 + 1 * 2 + 1 * 1` or `11`!

What's the biggest number you can represent with four decimal digits? `9999` or `10^4 - 1`. If we go any higher we'll need more digits to represent the number. 

What's the biggest number you can represent with four binary digits? Well that's `1111` or `2^4 - 1`. In other words `15`, one less than `16`. You'll notice that `16` is a lot less than ten thousand. Binary numbers take a lot of space to write down which is why we usually write numbers in hexadecimal instead. That is, base sixteen. If you've ever seen white written as `FFFFFF` in CSS or something that's specifying the values in the red, blue, and green channels.

> end skip

Earlier I said an `int` is *usually* a `32` bit signed integer. One of the really fun features of C is that the exact size of many of the basic data types is platform dependant. This is another sign of C's age. You can specify the exact sizes you want with a built in library but let's not worry about that for now. For the sake of my sanity I'm not going to qualify the sizes of types moving forwards.

C has a `float` type and a `double` type. These are for representing decimal numbers. The `double` type is, as you can expect, twice as big as a `float`.

C has a type `size_t`. This is the largest *unsigned* integer type your system can natively represent. It's an unsigned `64` bit integer. Unsigned simply means that it can't represent negative numbers. We'll see its use later.

C has a type `char` for individual ascii characters. I might come back and talk more about strings in which case we'll talk about `char` a whole bunch. Stay tuned.

You might wonder if C has booleans, it must right? No! Well, kind of! By default C does not have a boolean type, it uses integers. There is a bool type in the standard library but again, we're not gonna worry about it.

Finally we'll see examples of `void` and `NULL` later.

## Functions

doubler

```c
#include <stdio.h>

int doubler(int x){
    return x * 2;
}

int main(){
    int a = doubler(5);
    printf("%i\n", a);
    return 0;
}
```

### Forward Declare

Alternately with a forward declare

```c
#include <stdio.h>

int doubler(int x);

int main(){
    int a = doubler(5);
    printf("%i\n", a);
    return 0;
}

int doubler(int x){
    return x * 2;
}
```

## Arrays

Array literals are static. Dynamic arrays are a whole other thing that we'll get to.

Consider the following:

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

You'll notice a few major differences from JS. Starting with the first line:

`int nums[] = {3, 5, 6, 11, 2};`

Here we are specifying an array of integers. We specify its an array with brackets *after* the variable name.

### Summer

```c
#include <stdio.h>

int summer(int nums[], int len){
    int total = 0;
    for(int i = 0; i < len; i++){
        total += nums[i];
    }
    return total;
}

int main(){
    int nums[] = {3, 5, 6, 11, 2};
    printf("%i\n", summer(nums, 5));
    return 0;
}
```

## Pointers

```c
#include <stdio.h>

int main(){
    int a = 5;
    int* ap = &a;
    printf("%i\n", a);
    printf("%p\n", ap);
    return 0;
}
```

```c
#include <stdio.h>

int main(){
    int a = 5;
    int* ap = &a;
    int b = *ap;
    printf("%i\n", a);
    printf("%p\n", ap);
    a++;
    printf("%i\n", b);
    printf("%i\n", *ap);
    return 0;
}
```

inc

```c
#include <stdio.h>

void inc(int* xp){
    (*xp)++;
}

int main(){
    int a = 5;
    inc(&a);
    printf("%i\n", a);
    return 0;
}
```

double_all

```c
#include <stdio.h>

void double_all(int* nums, int len){
    for(int i = 0; i < len; i++){
        nums[i] *= 2;
    }
}

int main(){
    int len = 5;
    int nums[] = {3, 5, 6, 11, 2};
    double_all(nums, len);
    for(int i = 0; i < len; i++){
        printf("%i\n", nums[i]);
    }
    return 0;
}
```

## Structs

## Simple Macros and Headers

include, define, headers, and header guards

## malloc, calloc, memcpy, and free

## Dynamic arrays

push, pop, print