#include <stdio.h>
#include <stdint.h>

#define UNICOPY_DST_USER     0
#define UNICOPY_DST_KERN     1
#define UNICOPY_DST_PHYS     2
#define UNICOPY_SRC_USER     0
#define UNICOPY_SRC_KERN     4
#define UNICOPY_SRC_PHYS     8
size_t unicopy(unsigned mode, uintptr_t dst, uintptr_t src, size_t size);

#define KERN_INFO_VA         0
#define KERN_INFO_PA         1
uintptr_t get_kern_info(unsigned key);

int main(void)
{
    uint64_t va, pa;
    uint8_t buf[32];
    size_t ret, i;

    va = get_kern_info(KERN_INFO_VA);
    pa = get_kern_info(KERN_INFO_PA);

    ret = unicopy(UNICOPY_DST_USER | UNICOPY_SRC_KERN, (uint64_t)buf, va, sizeof(buf));
    if(ret != sizeof(buf)) {
        printf("copy (%llx) failed - %ld\n", va, ret);
        return 1;
    }
    printf("%llx:", va);
    for(i=0; i<ret; i++)
        printf(" %02x", buf[i]);
    printf("\n");

    ret = unicopy(UNICOPY_DST_USER | UNICOPY_SRC_PHYS, (uint64_t)buf, pa, sizeof(buf));
    if(ret != sizeof(buf)) {
        printf("copy (%llx) failed - %ld\n", pa, ret);
        return 1;
    }
    printf("%llx:", pa);
    for(i=0; i<ret; i++)
        printf(" %02x", buf[i]);
    printf("\n");

    return 0;
}
