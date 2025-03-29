# Lecture 09 Exercises

# Circular buffer with arrays
A circular buffer (also known as a ring buffer or cyclic buffer) is similar to a regular list, but with a key difference: when the number of stored values exceeds the buffer’s capacity, the oldest value is overwritten. Circular buffers are commonly used in real-world applications such as:
- Logging, where older entries are replaced to conserve disk space.
- Data streaming, where data is continuously produced and consumed (e.g., when streaming on Netflix, Twitch, or YouTube).

Write a C program that implements a circular buffer capable of storing integer values.

**Requirements**
- The program should accept an arbitrary number of arguments (between 0 and 255), where:
  - The first argument (index 1) specifies the buffer size (the maximum number of values it can hold).
  - Any subsequent arguments initialize the buffer with values.
- If the buffer reaches its maximum capacity:
  - New values should overwrite the oldest ones, following the first-in, first-out (FIFO) principle.
- Whenever a value is added, the program should print the current buffer contents to standard output.

_**Hint** The first arguments is always the executable name_
_**Hint** It is probably not a good idea to use the subscript operator (`[]`) when reading and writing values in the buffer_

**Passing command-line arguments to the debugger**
Since the program takes command-line arguments, you’ll need to configure them in VSCode:
1. Open `launch.json`.
2. Locate the `args` field.
3. Modify the values as needed (a sample configuration is provided, but feel free to change it).

You can also call the program from a terminal as shown below:

**Example output**
```
$ ./main-array.o 4 1 2 3 4 5 6
1 0 0 0
1 2 0 0
1 2 3 0
1 2 3 4
5 2 3 4
5 6 3 4
```

**Handout**
It's a good idea to initialize the array to make it easier debug. Here is a function that does that
```c
void init(int* array, int count) {
  for(int i = 0; i < count; i++) {
    array[i] = 0;
  }
}
```

## Add new values
Extend the program from [Exercise 0x00](#exercise-0x00-circular-buffer-with-arrays) to prompt the user to enter new integers in an infinite loop.

**Example output**
```
$ ./main-array.o 8 1 2 3 4 5 6 7     
1 0 0 0 0 0 0 0 
1 2 0 0 0 0 0 0 
1 2 3 0 0 0 0 0 
1 2 3 4 0 0 0 0 
1 2 3 4 5 0 0 0 
1 2 3 4 5 6 0 0 
1 2 3 4 5 6 7 0 
Enter next value: 8
1 2 3 4 5 6 7 8 
Enter next value: 9
9 2 3 4 5 6 7 8 
Enter next value: 10
9 10 3 4 5 6 7 8 
Enter next value: 
```

_**Hint** Don't worry about non-integer inputs—we'll assume our users are nice and will always enter integers!_