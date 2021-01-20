#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants/constants.h"
#include "movieList/movieList.h"

int main(int argc, char *argv[])
{
  // Assert correct param count
  if (!hasRequiredParams(argc))
  {
    return EXIT_FAILURE;
  }

  // Create movie linked list reading from file passed as param
  struct movie *movieList = createMovieList(argv[1]);

  // Assert correct param count
  if (!movieListHasContent(movieList, argv[1]))
  {
    return EXIT_FAILURE;
  }

  // Create array of unique movie years
  int yearSize = 0;
  int *uniqueMovieYears = createUniqueMovieYearsArr(movieList, &yearSize);

  // User inteface handler
  char *language;
  unsigned short year;
  int option;
  do
  {
    option = promptUserForFlowOption();
    switch (option)
    {
    // 1 - Filter movies by specific year
    case 1:
      year = promptUserForMovieYear();
      filteMoviesByYear(movieList, year);
      break;
    // 2 - For each unique year, print movie with highest ratings
    case 2:
      printMoviesWithHighestRatingsPerYear(movieList, uniqueMovieYears, yearSize);
      break;
    // 3 - Filter movies by exact mach of language
    case 3:
      language = promptUserForLanguage(&language);
      printMoviesOfCertainLanguage(movieList, language);
      free(language);
      break;
    // 4 - Release memory and exit program with code 0 (success)
    case 4:
      free(uniqueMovieYears);
      freeMovieList(movieList);
      printf("%s", GOODBYE_MSG);
      return EXIT_SUCCESS;
      break;
    // Other - Print bad input message
    default:
      puts(INVALID_USER_INPUT_MSG);
    }
  } while (TRUE);
}