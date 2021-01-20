#ifndef CONSTANTS_H
#define CONSTANTS_H
#define TRUE 1
#define FALSE 0
#define MAX_MOVIE_YEARS 122
#define MAX_LANGUAGE_LENGTH 20
#define MIN_ARGUMENT_COUNT 2

char *MISSING_FILE_PARAM_MSG;
char *LIST_CREATION_SUCCESS_MSG;
char *LIST_CREATION_SUCCESS_EMPTY_MSG;
char *USER_OPTIONS;
char *OPTION_PROMPT;
char *INVALID_USER_INPUT_MSG;
char *GOODBYE_MSG;
char *INPUT_YEAR_MSG;
char *NO_YEAR_RESULT_MSG;
char *SELECTED_YEAR_MSG;
char *TOTAL_RECORDS_FOUND_IN_YEAR;
char *INPUT_LANGUAGE;
char *LANGUAGE_EMPTY_RECORDS_MSG;
char *LANGUAGE_RECORDS_MSG;

int arrayContainsValue(int *, int, int);
void *promptUserForLanguage();
int hasRequiredParams(int argc);
int promptUserForFlowOption();
unsigned short promptUserForMovieYear();

#endif