This is a program that calculates how may subtractions are needed to reach Kaprekar's Constant



**Kaprekar's Constant:**

Any four digit number that contains at least two different digits can be rearranged to two different numbers.

One that is sorted with the digits from highest to lowest (number a), and the other from lowest to highest (number b).

The theory is that if we subtract b from a (a - b) and we rearrange the number again and re-do this again and again, eventually we will reach the number 6174 (Kaprekar's Constant).



It is a simple C program, that utilizes math.h (for one use of the pow function), stdlib.h (for the qsort function) and stdio.h for the standard input and output. The program makes the appropriate checks and calculates the number of subtractions. The program also prints every subtraction made.

