#include <stdio.h>
#include "logger.h"
/*----------------------------------------------------------------------------*/
/* GLOBAL                                                                     */
/*----------------------------------------------------------------------------*/
FILE *log_file = NULL;
/*----------------------------------------------------------------------------*/
/* PRIVATE FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
void Logger_WriteMessage (const char *prefix, const char *message)
{
	if (log_file != NULL) {
		fprintf (log_file, "[%s]:\"%s\"\n", prefix, message);
		fflush (log_file);
	}
}
/*----------------------------------------------------------------------------*/
/* PUBLIC  FUNCTIONS                                                          */
/*----------------------------------------------------------------------------*/
void Logger_Init (const char *logfile_name)
{
	log_file = fopen (logfile_name, "w+");
}
/*----------------------------------------------------------------------------*/
void Logger_INFO (const char *message)
{
	Logger_WriteMessage ("INFO", message);
}
/*----------------------------------------------------------------------------*/
void Logger_WARNING (const char *message)
{
	Logger_WriteMessage ("WARNING", message);
}
/*----------------------------------------------------------------------------*/
void Logger_ERROR (const char *message)
{
	Logger_WriteMessage ("ERROR", message);
}
/*----------------------------------------------------------------------------*/
void Logger_Destroy ()
{
	fclose (log_file);
}
