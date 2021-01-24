#ifndef CONSTANTS_H
#define CONSTANTS_H
#define TRUE 1
#define FALSE 0
#define MAX_FILENAME_LENGTH 255

char *FILE_NAME_PREFIX;
char *USER_MAIN_MENU_LIST;
char *USER_PROCESS_FILE_MENU_LIST;
char *MAIN_MENU_OPTION_PROMPT;
char *FILE_PROCESS_MENU_OPTION_PROMPT;
char *INVALID_USER_INPUT_MSG;
char *GOODBYE_MSG;
char *PROCESSING_FILE_CONFIRM_MSG;
char *FILENAME_PROMPT;

int handleInputOptionRequest(char *optionPromptMessage, char *menuList);
int promptUserForMainMenuOption();
int promptUserForFileProcessingMenuOption();
int printGoodByeAndReturnSuccess();
void printWrongOptionMessage();
int strMatchesPrefix(char *, char *);
void printFileToProcessMessage(char *);
void printFileNotFoundMessage(char *);

#endif