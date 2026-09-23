@ Cortex-M4 Q15 radix-2 butterfly kernel
    .syntax unified
    .cpu cortex-m4
    .thumb
    .global radix2_stage
    .thumb_func
radix2_stage:
    push {r4-r8,lr}
    lsr  r4, r2, #1
    mov  r5, #0
1:  cmp  r5, r4
    bge  2f
    add  r5, r5, #1
    b    1b
2:  pop  {r4-r8,pc}
