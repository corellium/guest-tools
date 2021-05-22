.align 4
.global conslog_str
conslog_str:
    mov x1, x0
    mov x6, #16
1:  cbz x6, 2f
    sub x6, x6, #1
    ldrb w0, [x1]
    cbz w0, 3f
    mov w0, #0xFFFF0000
    mrs xzr, pmcr_el0
    hvc #0x6C43
    tbnz w0, #31, 3f
    add x1, x1, x0
    cbz w0, 1b
    mov x6, #16
    b 1b
2:  mov w0, #0x80000000
3:  ret
