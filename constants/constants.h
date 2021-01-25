#ifndef CONSTANTS_H
#define CONSTANTS_H
#define TRUE 1
#define FALSE 0
#define MAX_POSIX_FILENAME_LENGTH 255
#define MAX_MOVIE_YEARS 122

char *FILE_NAME_PREFIX;
char *ONID_ID_STR;
char *MOVIE_STR;
int DIR_PERMISSIONS;

char *USER_MAIN_MENU_LIST;
char *USER_PROCESS_FILE_MENU_LIST;
char *MAIN_MENU_OPTION_PROMPT;
char *FILE_PROCESS_MENU_OPTION_PROMPT;
char *INVALID_USER_INPUT_MSG;
char *GOODBYE_MSG;
char *PROCESSING_FILE_CONFIRM_MSG;
char *FILENAME_PROMPT;
char *LIST_CREATION_SUCCESS_MSG;
char *LIST_CREATION_SUCCESS_EMPTY_MSG;
char *DIRECTORY_CREATION_SUCCESS_MSG;
char *CSV_FILE_EXTENSION;
char *INVALID_FILENAME_MSG;
char *NO_FILE_FOUND_IN_FOLDER_MSG;

int handleInputOptionRequest(char *, char *);
int promptUserForMainMenuOption();
int promptUserForFileProcessingMenuOption();
int printGoodByeAndReturnSuccess();
void printWrongOptionMessage();
int strMatchesPrefix(char *, char *);
void printFileToProcessMessage(char *);
void printFileNotFoundMessage(char *);
int createRandomNumberInRange();
int arrayContainsValue(int *, int, int);
int filenameContainsExtension(char *, char *);
int stringMatchesPrefixAndExtension(char *);

#endif