#include "map.h"
//------------------------------------------------------------------------------
// DEFINES
//------------------------------------------------------------------------------
#define NUM_TESTS
//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------
void Test_MapParseMapStr (void)
{
struct map;
char buffer[100]
unsigned int i;
	Map_Init (&map);
	for (i = 0; i < NUM_TESTS; i++)	{
		
		Map_ParseMapStr (&map, &buffer);
	}
	Map_Destroy (&map);

}
//------------------------------------------------------------------------------
int main (int argc, char *argv[])
{
	Test_MapParseMapStr ();
	return 0;
}

