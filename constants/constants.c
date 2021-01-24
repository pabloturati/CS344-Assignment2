#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

// Constants
char *FILE_NAME_PREFIX = "movies_";
char *ONID_ID_STR = "turatip";
char *MOVIE_STR = "movies";
int UPPER_RAN_LIM = 99999;
int LOW_RAN_LIM = 0;
int DIR_PERMISSIONS = 0750;

// User interface messages
char *USER_MAIN_MENU_LIST = "\n1. Select file to process\n2. Exit the program\n";
char *USER_PROCESS_FILE_MENU_LIST = "\nWhich file you want to process?\nEnter 1 to pick the largest file\nEnter 2 to pick the smallest file\nEnter 3 to specify the name of a file\n";
char *MAIN_MENU_OPTION_PROMPT = "Enter a choice from 1 to 2: ";
char *FILE_PROCESS_MENU_OPTION_PROMPT = "Enter a choice from 1 to 3: ";
char *INVALID_USER_INPUT_MSG = "\nYou entered an incorrect choice. Try again.\n";
char *GOODBYE_MSG = "Freeing allocated memory done, good bye!\n";
char *PROCESSING_FILE_CONFIRM_MSG = "\nNow processing the chosen file named %s\n";
char *FILENAME_PROMPT = "Enter the complete file name: ";
char *FILENAME_NOT_FOUND_MSG = "\nFile named \"%s\" was not found in this directory\n";
char *LIST_CREATION_SUCCESS_MSG = "Processed file %s and parsed data for %zu movies\n\n";
char *LIST_CREATION_SUCCESS_EMPTY_MSG = "Processed file but list is empty\n\n";

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

// User request and interaction methods

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
Prints message to stdout regarding wrong option
Input: None
Output: Void. Prints message to srdout
*/
void printWrongOptionMessage()
{
  puts(INVALID_USER_INPUT_MSG);
}

/* 
Prints "File not found" message to stdout
Input: None
Output: Void. Prints message to srdout
*/
void printFileNotFoundMessage(char *filename)
{
  printf(FILENAME_NOT_FOUND_MSG, filename);
}

/* 
Prints message to std regarding wrong option
Input: fileName (string)
Output: Void. Prints message to stdout
*/
void printFileToProcessMessage(char *filename)
{
  printf(PROCESSING_FILE_CONFIRM_MSG, filename);
}

// Data handling methods

/*
Function that matches a string to a prefix
Input: str (string), prefix (string)
Output: 1 for TRUE, -1
*/
int strMatchesPrefix(char *str, char *prefix)
{
  return strncmp(prefix, str, strlen(prefix)) == 0;
}

/*
Function to create a random number in the range 0 -> 99999
Input: str (string), prefix (string)
Output: 1 for TRUE, -1

Refrence:  Adapted from code from https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
 and https://www.geeksforgeeks.org/generating-random-number-range-c/
*/
int createRandomNumberInRange()
{
  return (rand() % (UPPER_RAN_LIM - LOW_RAN_LIM + 1)) + LOW_RAN_LIM;
}

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