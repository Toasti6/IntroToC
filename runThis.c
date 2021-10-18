#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>

int main()

{
    int i;

    for(i = 100; i < 500; i += 5)
        {           
            Beep(i, 250);
            printf("beep = %d\n", i);
        }

    for(i = 500; i > 100; i -= 5)
        {           
            Beep(i, 250);
            printf("beep = %d\n", i);
        }

    return 0;
}