#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void allocate(int value)
{
    int *ptr = NULL;
    ptr = malloc(100000 * sizeof(int));
     if (ptr == NULL)
  {
    perror ("Error. Allocation was unsuccessful"); //displays the string, followed by the textual representation of the current errno value.
    exit(EXIT_FAILURE);
  }
    *ptr = value;
    printf("test of allocated memory: %i\n");
}

int main()
{
    while (1) //run this function indefinetely

    {
        allocate(69);
    }
    return 0;
}
