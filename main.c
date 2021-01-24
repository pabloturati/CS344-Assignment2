#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants/constants.h"
#include "movieList/movieList.h"
#include "fileHandlers/fileHandlers.h"

void processFileMenu()
{
  int option;
  do
  {
    option = promptUserForFileProcessingMenuOption();
    switch (option)
    {
    // 1 - pick the largest file
    case 1:
      printf("second 1");
      break;
    // 2 - pick the smallest file
    case 2:
      printf("second 2");
      break;
    // 3 - to specify the name of a file
    case 3:
      printf("second 3");
      break;
    // Other - Print bad input message
    default:
      printWrongOptionMessage();
    }
  } while (TRUE);
}

int main()
{
  // int option;
  // do
  // {
  //   option = promptUserForMainMenuOption();
  //   switch (option)
  //   {
  //   // 1 - Select file to process
  //   case 1:
  //     processFileMenu();
  //     break;
  //   // 2 - Exit the program
  //   case 2:
  //     return printGoodByeAndReturnSuccess();
  //   // Other - Print bad input message
  //   default:
  //     printWrongOptionMessage();
  //   }
  // } while (TRUE);
  findFileLargestFileFromPrefix();
}