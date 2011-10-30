#include <stdio.h>
#include <string.h>
#include "parse.h"
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* PUBLIC FUNCTIONS */
/*----------------------------------------------------------------------------*/
int KeyVal_Extract (
	const char *key_val_pair, 
	char *buf_for_key,
	char *buf_for_val,
	unsigned int separator
) {
char *space_point;
size_t space_pos;
size_t kv_length;
size_t value_length;
	/* TODO: make it based on sscanf function */
	space_point = strchr (key_val_pair, ' ');
	if (NULL == space_point)
		return -1;
	space_pos = space_point - key_val_pair;
	/* copy key to buffer */
	strncpy (buf_for_key, key_val_pair, space_pos);
	buf_for_key[space_pos] = '\0';
	/* copy value to buffer */
	kv_length = strlen(key_val_pair);
	value_length = kv_length - space_pos - 1; /* 1 is delimeter */
	strncpy (buf_for_val, &key_val_pair[space_pos + 1], value_length);
	buf_for_val[value_length] = '\0';
	return 0;
}

