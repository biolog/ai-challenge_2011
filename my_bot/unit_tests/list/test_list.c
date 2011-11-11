#include <stdio.h>
#include "list.h"
/*----------------------------------------------------------------------------*/
/* DEFINES                                                                    */
/*----------------------------------------------------------------------------*/
#define DEBUG_PRINT
/*----------------------------------------------------------------------------*/
/* GLOBALS                                                                    */
/*----------------------------------------------------------------------------*/
char *test_array[] = {"one", "two", "three", "four", "five", "six", 
                  "seven", "eight", "nine", "ten"};
unsigned int test_array_length = 10;
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void Test_OrdinaryCase (void)
{
struct list;
unsigned int i;
char *data;

        List_Init (&list);
        /* fill the list */
        for (i = 0; i < test_array_length; i++)
                List_Add (&list, test_array[i]);
        
        /* check the list*/
        data = List_GetNextData (&list, 1);
        while (data != NULL) {
                data = List_GetNextData (&list, test_array[i]);
#ifdef DEBUG_PRINT
                printf ("data %s\n", data);
#endif
        }
        List_Destroy (&list);
}
/*----------------------------------------------------------------------------*/
/* MAIN */
/*----------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{
        Test_OrdinaryCase ();
}

