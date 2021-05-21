/* struct rtc_time {
      uint64_t sec;
      uint32_t nsec;
   };
   int hyp_get_rtc(struct rtc_time *buf); */

.align 4
.global _hyp_get_rtc
_hyp_get_rtc:
    mov x1, x0
    mov x0, #0x180
    mrs xzr, cntpct_el0
    hvc #0x9402
    ret
