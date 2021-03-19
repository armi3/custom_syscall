# Custom Syscall
The file `is_balanced.c` contains a function that checks if an algebraic expression is opening and closing parenthesis and braces correctly.

This function is declared in the syscall table of our custom Linux kernel as shown in the picture. After the kernel is compiled using the script `deploy.sh` and the machine reboots, the syscall is now available for user processes and can be tested with the user program `test_is_balanced.c`.

![syscall](https://i.imgur.com/NvFZAz4.png)



## Test the syscall

To compile the user program and test the syscall, use:

```
gcc -o test_is_balanced test_is_balanced.c
```
This should be rejected:
```
./test_is_balanced '((2-2))('
```
Also this expression:
```
./test_is_balanced '((2-2*3))([['
```
And this should be accepted:
```
./test_is_balanced '[(6*3)-(66/6)]'
```

