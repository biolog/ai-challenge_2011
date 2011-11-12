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
struct list list;
unsigned int i;
char *data;

        List_Init (&list);
        /* fill the list */
        for (i = 0; i < test_array_length; i++) {
		printf ("[INFO]: Add data %s to list\n", test_array[i]);
                List_Add (&list, test_array[i]);
	}
        
        /* check the list*/
	List_ResetToFirst (&list);
        while (1) {
                data = List_GetNextData (&list);
		if (data == NULL)
			break;
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
	return 0;
}

