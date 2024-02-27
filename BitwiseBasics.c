#include <stdio.h>
#include <stdint.h>

/* If you change the datatype ensure to change the format specifer in scanf function */
typedef uint16_t datatype; 

void printBinary(datatype  value);
void set(datatype  value);
void toggle(datatype  value);
void reset(datatype  value);

void main(int argc, char *argv[])
{
    datatype value = 100, position = 0;

    /* Validate command line arguments s->set, g->get, t->toggle r->reset */
    if (argc != 2)
    {
        printf("Usage error \n ./exe s/t/g");
    }
    printBinary(value);
    switch(*argv[1])
    {
        case 's':
        case 'S': set(value);
                  break;
        case 't':
        case 'T': toggle(value);
                  break;
        case 'r':
        case 'R': reset(value);
                break;
        default : break;
    } 
}

/* Print the Binary of the value*/
void printBinary(datatype  value)
{
    for(int8_t iterate = ( (sizeof(datatype) * 8) -1); iterate >= 0; iterate--)
    {
        printf("%hd ", ((value >> iterate) & 1));
    }
    printf("\n");
    printf("Inside for Valus is : %hd\n", value);
}
/* Function to set a bit */
void set(datatype  value)
{
    datatype position = 0;
    printf("Enter the bit number to be set\n");
    scanf("%hd", &position);
    value = value | (1 << position);
    printf("After bit is set\n");
    printBinary(value);
}
/* Function to toggle a bit */
void toggle(datatype  value)
{
    datatype position = 0;
    printf("Enter the bit number to be reset\n");
    scanf("%hd", &position);
    value = value ^ (1 << position);
    printf("After bit is toggle\n");
    printBinary(value);
}
/* Function to reset a bit */
void reset(datatype  value)
{
    datatype position = 0;
    printf("Enter the bit number to be reset\n");
    scanf("%hd", &position);
    value = value & (~(1 << position));
    printf("After bit is reset\n");
    printBinary(value);
}
