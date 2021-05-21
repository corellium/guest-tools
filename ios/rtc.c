#include <stdint.h>
#include <stdio.h>

struct rtc_time {
    uint64_t sec;
    uint32_t nsec;
};
int hyp_get_rtc(struct rtc_time *buf);

int main(void)
{
    struct rtc_time rtc;
    int res;

    res = hyp_get_rtc(&rtc);
    if(!res)
        printf("RTC: %lld.%09d\n", rtc.sec, rtc.nsec);
    else
        printf("RTC: error %d\n", res);

    return 0;
}
