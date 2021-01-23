#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

// User interface messages
char *MISSING_FILE_PARAM_MSG = "Missing file to read\n";
char *LIST_CREATION_SUCCESS_MSG = "Processed file %s and parsed data for %zu movies\n\n";
char *LIST_CREATION_SUCCESS_EMPTY_MSG = "Processed file but list is empty\n\n";
char *USER_MAIN_MENU_LIST = "\n1. Select file to process\n2. Exit the program\n";
char *USER_PROCESS_FILE_MENU_LIST = "\nWhich file you want to process?\nEnter 1 to pick the largest file\nEnter 2 to pick the smallest file\nEnter 3 to specify the name of a file\n";
char *MAIN_MENU_OPTION_PROMPT = "Enter a choice from 1 to 2: ";
char *FILE_PROCESS_MENU_OPTION_PROMPT = "Enter a choice from 1 to 3: ";
char *INVALID_USER_INPUT_MSG = "\nYou entered an incorrect choice. Try again.\n";
char *GOODBYE_MSG = "Freeing allocated memory done, good bye!\n";

// Year messages
char *INPUT_YEAR_MSG = "Enter the year for which you want to see movies: ";
char *NO_YEAR_RESULT_MSG = "No data about movies released in the year %hu\n\n";
char *SELECTED_YEAR_MSG = "You selected %hu\n\n";
char *TOTAL_RECORDS_FOUND_IN_YEAR = "\n%hu total records found in year %hu\n\n";

// Language messages
char *INPUT_LANGUAGE = "Enter the language for which you want to see movies:";
char *LANGUAGE_CONFIRM_MSG = "You selected %s.\n\n";
char *LANGUAGE_RECORDS_MSG = "\nFound %d records in %s\n";
char *LANGUAGE_EMPTY_RECORDS_MSG = "No data about movies released in %s\n\n";

// Data validation methods

/* 
Looks to see if an integer array contains a specific integer value.
Input: array, size of the array and value to be searched (all integer type)
Output: 1 for True, 0 for False
*/
int arrayContainsValue(int *arr, int arrSize, int val)
{
  for (int i = 0; i < arrSize; i++)
  {
    if (arr[i] == val)
      return 1;
  }
  return 0;
}

/* 
Verifies if argument count is greater then minimum required
Input: array, size of the array and value to be searched (all integer type)
Output: 1 for True, 0 for False
*/
int hasRequiredParams(int argc)
{
  if (argc < MIN_ARGUMENT_COUNT)
  {
    printf("%s", MISSING_FILE_PARAM_MSG);
    return FALSE;
  }
  return TRUE;
}

// User request and interaction methods

/* 
Prompts user for language. To be used to filter movies by.
Input: None
Output: None. Writes on language (passed by ref.)
*/
void *promptUserForLanguage()
{
  char *language = (char *)calloc(MAX_LANGUAGE_LENGTH + 1, sizeof(char));
  printf("%s", INPUT_LANGUAGE);
  scanf("%s", language);
  printf(LANGUAGE_CONFIRM_MSG, language);
  return language;
}

/* 
Handles option request
Input: optionPromptMessage (string), menuList (string)
Output: option (integer)
*/
int handleInputOptionRequest(char *optionPromptMessage, char *menuList)
{
  int option;
  puts(menuList);
  printf("%s", optionPromptMessage);
  scanf("%d", &option);
  return option;
}

/* 
Prompts user for an option (1 and 2) for the menu option control flow
Input: None
Output: option (integer)
*/
int promptUserForMainMenuOption()
{
  return handleInputOptionRequest(MAIN_MENU_OPTION_PROMPT, USER_MAIN_MENU_LIST);
}

/* 
Prompts user for an option (1 thru 3) for the process file menu control flow
Input: None
Output: option (integer)
*/
int promptUserForFileProcessingMenuOption()
{
  return handleInputOptionRequest(FILE_PROCESS_MENU_OPTION_PROMPT, USER_PROCESS_FILE_MENU_LIST);
}

/* 
Prints success exit message and returns success message
Input: None
Output: 0 (integer)
*/
int printGoodByeAndReturnSuccess()
{
  printf("%s", GOODBYE_MSG);
  return EXIT_SUCCESS;
}

/* 
Communicates to user that he/she chose wrong option
Input: None
Output: Void. Prints message to srdout
*/
void printWrongOptionMessage()
{
  puts(INVALID_USER_INPUT_MSG);
}

/* 
Prompts user for a year option. To be used to filter movies by.
Input: None
Output: option (integer)
*/
unsigned short promptUserForMovieYear()
{
  unsigned short year;
  printf("%s", INPUT_YEAR_MSG);
  scanf("%hu", &year);
  printf(SELECTED_YEAR_MSG, year);
  return year;
}