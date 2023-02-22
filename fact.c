#include <stdio.h>
factorial(int argc, char *argv[])
{
    unsigned int iLoop,iFactorial = 1;
    int iNumber=0;
    printf("Enter a number: ");
    scanf("%d",&iNumber);
    if(iNumber < 0 )
    {
        printf("factorial of negative number dose not exist\n\n\n");
    }
    else
    {
        for(iLoop=1; iLoop<=iNumber; iLoop++)
        {
            iFactorial*= iLoop;
        }
        printf("\n\nFactorial of %d is: %u\n\n\n\n",iNumber,iFactorial);
    }
   // return 0;
}
