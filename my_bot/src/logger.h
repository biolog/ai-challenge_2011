#ifndef __LOGGER__
#define __LOGGER__
/*----------------------------------------------------------------------------*/
/* FUNCTIONS                                                                  */
/*----------------------------------------------------------------------------*/
void Logger_Init (const char *logfile_name);
void Logger_Destroy ();

void Logger_INFO    (const char *message);
void Logger_WARNING (const char *message);
void Logger_ERROR   (const char *message);
#endif
