#include <stdio.h>

#define STS_IG32    0xE
#define STS_TG32    0xF

typedef unsigned uint32_t;

#define SETGATE(gate, istrap, sel, off, del) { \
    (gate).gd_off_15_0 = (uint32_t)(off) & 0xffff;  \
    (gate).gd_ss = (sel);   \
    (gate).gd_args = 0; \
    (gate).gd_rsv1 = 0; \
    (gate).gd_type = (istrap) ? STS_TG32 : STS_IG32;    \
    (gate).gd_s = 0;    \
    (gate).gd_dpl = (del);  \
    (gate).gd_p = 1;    \
    (gate).gd_off_31_16 = (uint32_t)(off) >> 16;    \
}

struct gatedesc
{
    unsigned gd_off_15_0 : 16;
    unsigned gd_ss : 16;
    unsigned gd_args : 5;
    unsigned gd_rsv1 : 3;
    unsigned gd_type : 4;
    unsigned gd_s : 1;
    unsigned gd_dpl : 2;
    unsigned gd_p : 1;
    unsigned gd_off_31_16 : 16;
};


int main()
{
    unsigned before;
    unsigned intr;
    unsigned after;

    struct gatedesc gintr;

    intr = 8;
    before = after = 0;

    gintr = *( (struct gatedesc*)&intr);
    SETGATE(gintr, 0,1,2,3);
    intr = *(unsigned*)&(gintr);
    printf("intr is 0x%x\n", intr);
    printf("gintr is 0x%llx\n", gintr);
    return 0;
}