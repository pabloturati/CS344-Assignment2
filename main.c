#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constants/constants.h"
#include "fileHandlers/fileHandlers.h"

int main()
{
  int option;
  char *filename = (char *)calloc(MAX_POSIX_FILENAME_LENGTH + 1, sizeof(char));

  //Generates seed for pseudo random
  srand(time(0));

  // Interact with user in main menu
  do
  {
    option = promptUserForMainMenuOption();
    switch (option)
    {
    // 1 - Select file to process
    case 1:
      processFileMenu(filename);
      break;
    // 2 - Exit the program
    case 2:
      free(filename);
      return printGoodByeAndReturnSuccess();
    // Other - Print bad input message
    default:
      printWrongOptionMessage();
    }
  } while (TRUE);
  return 0;
}