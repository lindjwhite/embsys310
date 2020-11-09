1a) -2147483648
1b) 0x80000000
1c) Both N and V flags are set in the APSR register. The V flag is set in the case of an overflow and the N 
    flag is set when a value is detected as two's complement, or negative, and adding 1 to 0x7FFFFFFF results 
    in both of those conditions occuring.

2a) The value of counter in the "Locals" window changes to 0.
2b) In this case, only the V flag is set due to overflow caused by adding 1 to 0xFFFFFFFF. Since the number
    is not negative in this case, the N flag is 0, however, the Z flag is set because its 0.

3a) 2147483648
3b) This time N and V are both set again, even though the value is an unsigned integer. This is because the
    N flag is set when the value COULD be a two's complement value, even if we are using it as an unsigned
    integer. V was set due to another overflow.

4a) 0
4b) Neither the N or V flags are set. I understand why the N flag is not set, it would be the same regardless
    of being signed or unsigned. I do not understand why the overflow flag isn't set, as I would think this
    would result in an overflow?

5a) The variable "counter"'s scope is now global.
5b) No, it is not visible in "Locals" anymore.
5c) We can now track "counter" in the "Watch 1" window.
5d) 0x20000000

6a) 4 
6b) The "counter" value has changed because we are setting the pointer "p_int" to the memory address where counter
    is stored. Each time "p_int" is dereferenced and added to, the value of counter is changed because they
    are pointing to the same location in memory. Its as if we were to have set "p_int" to "&counter".

7a) 0x20000000
7b) RAM
7c) 4