#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "constants/constants.h"
#include "fileHandlers/fileHandlers.h"
#include "movieList/movieList.h"

/*
Function to create a directory, file per movie year with their titles
Input: filename (string)
Output:
*/

int processFile(char *filename)
{
  printFileToProcessMessage(filename);

  // Allocate memory for directory name
  char *dirname = (char *)calloc(MAX_POSIX_FILENAME_LENGTH, sizeof(char));
  createFolderWithRandom(dirname);

  // Create movie linked list reading from file passed as param
  struct movie *movieList = createMovieList(filename);

  // Assert movie list creation was successful
  if (!movieListHasContent(movieList, filename))
  {
    return EXIT_FAILURE;
  }

  // Create array of unique movie years
  int yearSize = 0;
  int *uniqueMovieYears = createUniqueMovieYearsArr(movieList, &yearSize);

  for (int yearIdx = 0; yearIdx < yearSize; yearIdx++)
    createFileWithMoviesPerYear(movieList, uniqueMovieYears[yearIdx], dirname);

  freeMovieList(movieList);
  free(dirname);
  return 0;
}

void processFileMenu(char *fileToProcess)
{
  int option;
  do
  {
    option = promptUserForFileProcessingMenuOption();
    switch (option)
    {
    // 1 - pick the largest file
    case 1:
      fileToProcess = findLargestFileFromPrefix();
      processFile(fileToProcess);
      break;
    // 2 - pick the smallest file
    case 2:
      fileToProcess = findSmallestFileFromPrefix();
      processFile(fileToProcess);
      break;
    // 3 - to specify the name of a file
    case 3:
      if (findFilenameFromuserInput(fileToProcess))
        processFile(fileToProcess);
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
  char *fileToProcess = (char *)calloc(MAX_POSIX_FILENAME_LENGTH + 1, sizeof(char));

  //Generates seed for pseudo random
  srand(time(0));

  do
  {
    option = promptUserForMainMenuOption();
    switch (option)
    {
    // 1 - Select file to process
    case 1:
      processFileMenu(fileToProcess);
      break;
    // 2 - Exit the program
    case 2:
      free(fileToProcess);
      return printGoodByeAndReturnSuccess();
    // Other - Print bad input message
    default:
      printWrongOptionMessage();
    }
  } while (TRUE);
  return 0;
}