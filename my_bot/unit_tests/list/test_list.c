#include <stdio.h>
#include "list.h"
/*----------------------------------------------------------------------------*/
/* DEFINES                                                                    */
/*----------------------------------------------------------------------------*/
#define DEBUG_PRINT
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void Test_OrdinaryCase (void)
{
char *test_array[] = {"one", "two", "three", "four", "five", "six", 
                      "seven", "eight", "nine", "ten"};
unsigned int test_array_length = 10;
char *result_array[];
struct list list;
unsigned int i;
unsigned int j;
unsigned int result = 0;
char *data;

        List_Init (&list);
        /* fill the list */
        for (i = 0; i < test_array_length; i++) {
#ifdef DEBUG_PRINT
		printf ("[INFO]: Add data %s to list\n", test_array[i]);
#endif
                List_Add (&list, test_array[i]);
	}
        
        /* check the list*/
	result_array = (char **) malloc (test_array_length);
	List_ResetToFirst (&list);
        while (1) {
                data = List_GetData (&list);
                List_SwitchToNext (&list);
		if (data == NULL)
			break;
#ifdef DEBUG_PRINT
                printf ("data %s\n", data);
#endif
		if (j > test_array_length - 1) {
			printf ("[RESULT]: Test_OrdinaryCase: FAIL\n");
		}
		result_array[j++] = data;
        }
        List_Destroy (&list, 0);
	if (result == 0)
		printf ("[RESULT]: Test_OrdinaryCase: OK\n");
	else
		printf ("[RESULT]: Test_OrdinaryCase: FAIL\n");
	free (result_array);
}
/*----------------------------------------------------------------------------*/
/* MAIN */
/*----------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{
        Test_OrdinaryCase ();
	return 0;
}

