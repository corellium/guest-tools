/* #define UNICOPY_DST_USER     0
   #define UNICOPY_DST_KERN     1
   #define UNICOPY_DST_PHYS     2
   #define UNICOPY_SRC_USER     0
   #define UNICOPY_SRC_KERN     4
   #define UNICOPY_SRC_PHYS     8
   size_t unicopy(unsigned mode, uintptr_t dst, uintptr_t src, size_t size); */

.align 4
.global _unicopy
_unicopy:
    uxtb x0, w0
    orr x5, x0, #0x100
    mov x4, #0
    mov x6, #16
1:  cbz x3, 2f
    tst x5, #12
    bne 4f
    ldrb w0, [x2]
4:  tst x5, #3
    bne 5f
    strb w0, [x1]
5:  mov x0, x5
    mrs xzr, cntpct_el0
    hvc #0x9402
    cbnz x0, 3f
    sub x6, x6, #1
    cbz x6, 2f
    b 1b
3:  mov x6, #16
    add x1, x1, x0
    add x2, x2, x0
    sub x3, x3, x0
    add x4, x4, x0
    b 1b
2:  mov x0, x4
    ret

/* #define KERN_INFO_VA         0
   #define KERN_INFO_PA         1
   uintptr_t get_kern_info(unsigned key); */
.align 4
.global _get_kern_info
_get_kern_info:
    mrs xzr, cntpct_el0
    hvc #0x9402
    ret

