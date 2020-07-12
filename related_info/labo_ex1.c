int count  = 1;
int value = 1;
int buf[10];


int main()
{
    asm(
        "cld \n\t"
        "rep \n\t"
        "stosl"
        :
        : "C" (count), "a" (value), "D" (buf[0])
        :
    );
}

