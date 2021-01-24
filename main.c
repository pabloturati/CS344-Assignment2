#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants/constants.h"
#include "fileHandlers/fileHandlers.h"

void processFileMenu(char *userInput)
{
  int option;
  char *fileToProcess;
  do
  {
    option = promptUserForFileProcessingMenuOption();
    switch (option)
    {
    // 1 - pick the largest file
    case 1:
      fileToProcess = findLargestFileFromPrefix();
      printFileToProcessMessage(fileToProcess);
      break;
    // 2 - pick the smallest file
    case 2:
      fileToProcess = findSmallestFileFromPrefix();
      printFileToProcessMessage(fileToProcess);
      break;
    // 3 - to specify the name of a file
    case 3:
      if (findFilenameFromuserInput(userInput))
      {
        printFileToProcessMessage(userInput);
      }
      break;
    // Other - Print bad input message
    default:
      printWrongOptionMessage();
    }
  } while (TRUE);
}

int main()
{
  int option;
  char *userInput = (char *)calloc(MAX_FILENAME_LENGTH + 1, sizeof(char));
  do
  {
    option = promptUserForMainMenuOption();
    switch (option)
    {
    // 1 - Select file to process
    case 1:
      processFileMenu(userInput);
      break;
    // 2 - Exit the program
    case 2:
      return printGoodByeAndReturnSuccess();
    // Other - Print bad input message
    default:
      printWrongOptionMessage();
    }
  } while (TRUE);
}