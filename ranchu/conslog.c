#include <stdint.h>
#include <stdio.h>

int conslog_str(char *str);

#define LINE_MAX 4096

static char line[LINE_MAX];

int main(void)
{
    int res;

    while(fgets(line, LINE_MAX - 1, stdin)) {
        res = conslog_str(line);
        if(res < 0) {
            fprintf(stderr, "error: returned 0x%08x\n", res);
            return 1;
        }
    }

    return 0;
}
