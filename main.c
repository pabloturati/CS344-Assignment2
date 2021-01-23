#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants/constants.h"
#include "movieList/movieList.h"

void processFileMenu()
{
  int option;
  do
  {
    option = promptUserForFileProcessingMenuOption();
    switch (option)
    {
    // 1 - Filter movies by specific year
    case 1:
      // year = promptUserForMovieYear();
      // filteMoviesByYear(movieList, year);
      printf("second 1");
      break;
    // 2 - For each unique year, print movie with highest ratings
    case 2:
      // printMoviesWithHighestRatingsPerYear(movieList, uniqueMovieYears, yearSize);
      printf("second 2");
      break;
    // 3 - Filter movies by exact mach of language
    case 3:
      // language = promptUserForLanguage(&language);
      // printMoviesOfCertainLanguage(movieList, language);
      // free(language);
      printf("second 3");
      break;
    // Other - Print bad input message
    default:
      printWrongOptionMessage();
    }
  } while (TRUE);
}

int mainMenu()
{
  int option;
  do
  {
    option = promptUserForMainMenuOption();
    switch (option)
    {
    // 1 - Select file to process
    case 1:
      processFileMenu();
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

int main(int argc, char *argv[])
{
  // // Assert correct param count
  // if (!hasRequiredParams(argc))
  // {
  //   return EXIT_FAILURE;
  // }

  // // Create movie linked list reading from file passed as param
  // struct movie *movieList = createMovieList(argv[1]);

  // // Assert correct param count
  // if (!movieListHasContent(movieList, argv[1]))
  // {
  //   return EXIT_FAILURE;
  // }

  // // Create array of unique movie years
  // int yearSize = 0;
  // int *uniqueMovieYears = createUniqueMovieYearsArr(movieList, &yearSize);

  // // User inteface handler
  // char *language;
  // unsigned short year;

  return mainMenu() ? EXIT_SUCCESS : EXIT_FAILURE;
}