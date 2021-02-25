Implementation of **circular** queues (implemented as an array with *front* and *rear* indices) using two different ways:
1. Using a variable to count entries (Relevant files: ```queue-counter.h``` and ```queue-counter-impl.c```
2. Using *special values* to indicate the completeness: ```queue-special.h``` and ```queue-special-impl.c```
The implementation (the ones with a ```-impl```) files can be compiled with another file say ```xyz.c``` like so:
```c
gcc xyz.c queue-??-impl.c -o xyz 
```
The name of the executable can be changed according to your will, along with any of the relevant implementations.\
It must be noted here that the only difference in the implementation is the method of checking for empty/full queues.
