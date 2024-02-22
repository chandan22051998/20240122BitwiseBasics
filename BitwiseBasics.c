#include <stdio.h>
#include <stdint.h>

typedef uint8_t datatype;

void printBinary(datatype  value);

void main(int argc, char *argv[])
{
    datatype value = 100, position = 0;

    /* Validate command line arguments s->set, g->get, t->toggle r->reset */
    if(argc != 2)
    {
        printf("Usage error \n ./exe s/t/g");
    }
    printBinary(value);

    if((*argv[1] == 's') || (*argv[1] == 'S'))
    {
        printf("Enter the bit number to be set\n");
        scanf("%hhd", &position);
        value = value | (1 << position);
        printf("After bit is set\n");
        printBinary(value);
    }   
}

/* Print the Binary of the value*/
void printBinary(datatype  value)
{
    for(int8_t iterate = 7; iterate >= 0; iterate--)
    {
        printf("%d ", ((value >> iterate) & 1));
    }
    printf("\n");
    printf("Inside for Valus is : %d\n", value);
}
