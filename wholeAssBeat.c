#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>

int main()

{
    int i;

    for(i = 0; i < 20; i++)
        {           
            Beep(8000, 100);
            Beep(10000, 100);
            Beep(8000, 100);
            Beep(11000, 100);
            Beep(9000, 100);
            Beep(10000, 100);
            Beep(8000, 100);
            Beep(10000, 100);
            printf("beep = %d\n", i);
        }

    

    return 0;
}