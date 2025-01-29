nthFibonacci:
        push    {r4, r7, lr}    @ Save registers on stack (r4 for temp storage, r7 frame pointer, lr return address)
        sub     sp, sp, #12     @ Allocate 12 bytes on stack
        add     r7, sp, #0      @ Set up frame pointer
        str     r0, [r7, #4]    @ Store input parameter n (from r0) on stack (at [r7+4])
        
        @ Check if n <= 1 (base case)
        ldr     r3, [r7, #4]    @ Load n into r3
        cmp     r3, #1          @ Compare n with 1
        bgt     .L2             @ If n > 1, branch to recursive case
        ldr     r3, [r7, #4]    @ Load n for return value
        b       .L3             @ Branch to return

.L2:    @ Recursive case: F(n-1) + F(n-2)
        @ Calculate F(n-1)
        ldr     r3, [r7, #4]    @ Load n
        subs    r3, r3, #1      @ Calculate n-1
        mov     r0, r3          @ Set up parameter for recursive call
        bl      nthFibonacci    @ Call F(n-1)
        mov     r4, r0          @ Store result of F(n-1) in r4

        @ Calculate F(n-2)
        ldr     r3, [r7, #4]    @ Load n again
        subs    r3, r3, #2      @ Calculate n-2
        mov     r0, r3          @ Set up parameter
        bl      nthFibonacci    @ Call F(n-2)
        mov     r3, r0          @ Store result in r3
        
        add     r3, r3, r4      @ Add F(n-1) + F(n-2)

.L3:    @ Return section
        mov     r0, r3          @ Move result to return register
        adds    r7, r7, #12     @ Clean up stack
        mov     sp, r7          @ Restore stack pointer
        pop     {r4, r7, pc}    @ Restore registers and return

main:
        push    {r7, lr}        @ Save frame pointer and return address
        sub     sp, sp, #8      @ Allocate 8 bytes on stack
        add     r7, sp, #0      @ Set up frame pointer
        movs    r0, #44         @ Load parameter n=44
        bl      nthFibonacci    @ Call nthFibonacci(44)
        str     r0, [r7, #4]    @ Store result
        movs    r3, #0          @ Prepare return value 0
        mov     r0, r3          @ Move return value to r0
        adds    r7, r7, #8      @ Clean up stack
        mov     sp, r7          @ Restore stack pointer
        pop     {r7, pc}        @ Restore registers and return