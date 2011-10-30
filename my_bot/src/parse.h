#ifndef __PARSE__
#define __PARSE__
/*----------------------------------------------------------------------------*/
/* FUNCTIONS */
/*----------------------------------------------------------------------------*/
/* @brief Function extract key and value from key-value pair.
 * @param key_val_pair pointer to key-val pair
 * @param buf_for_key  pointer to buffer for key, must have enought space
 * @param buf_for_val  pointer to buffer for value, must have enought space
 * @param separator    code of seperator symbol
 * @return  0 if extraction sucsessfull
 * @retunr -1 if cant't find separator value in input string
 */
int KeyVal_Extract (
	const char *key_val_pair, 
	char *buf_for_key,
	char *buf_for_val,
	unsigned int separator
);
#endif
