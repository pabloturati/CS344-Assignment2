#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "fileHandlers.h"
#include "../constants/constants.h"
#include "../movieList/movieList.h"

/* Struct to hold file object name and size */
struct file_data
{
  off_t size;
  char *name;
};

/*
Returns largest file with same prefix in current directory.  
Input: fileToProcess (string) - pass-by-reference
Output: name of smallest file in current directory (string by reference), 
  TRUE for sucess, FALSE and error message
Code adapted from 3_5_stat_example 
*/
int findSmallestFileFromPrefix(char *filename)
{
  DIR *currDir = opendir(".");
  struct dirent *dirPtr;
  struct stat dirMetaData;

  struct file_data smallest;

  //Sets initial smallest size to 0 to default smallest to first file
  smallest.size = 0;

  while ((dirPtr = readdir(currDir)) != NULL)
  {
    if (stringMatchesPrefixAndExtension(dirPtr->d_name))
    {
      //Get metadata for current file entry
      stat(dirPtr->d_name, &dirMetaData);
      if (smallest.size == 0 || dirMetaData.st_size < smallest.size)
      {
        smallest.name = dirPtr->d_name;
        smallest.size = dirMetaData.st_size;
      }
    }
  }
  closedir(currDir);

  // If not file was found in the loop
  if (smallest.size == 0)
  {
    printf("%s", NO_FILE_FOUND_IN_FOLDER_MSG);
    return FALSE;
  }
  // Else copy
  strcpy(filename, smallest.name);
  return processFile(filename);
}

/*
Returns largest file with same prefix in current directory.  
Input: fileToProcess (string) - pass-by-reference
Output: name of smallest file in current directory (string by reference), 
  TRUE for sucess, FALSE and error message
Code adapted from 3_5_stat_example 
*/
int findLargestFileFromPrefix(char *filename)
{
  DIR *currDir = opendir(".");
  struct dirent *dirPtr;
  struct stat dirMetaData;

  struct file_data largest;

  // Sets initial largest size to 0 to default largest to first file
  largest.size = 0;

  while ((dirPtr = readdir(currDir)) != NULL)
  {
    if (stringMatchesPrefixAndExtension(dirPtr->d_name))
    {
      // Get metadata for current file entry
      stat(dirPtr->d_name, &dirMetaData);
      if (largest.size == 0 || dirMetaData.st_size > largest.size)
      {
        largest.name = dirPtr->d_name;
        largest.size = dirMetaData.st_size;
      }
    }
  }
  closedir(currDir);

  // If not file was found in the loop
  if (largest.size == 0)
  {
    printf("%s", NO_FILE_FOUND_IN_FOLDER_MSG);
    return FALSE;
  }
  // Else copy
  strcpy(filename, largest.name);
  return processFile(filename);
}

/*
Prompt user for input and returns largest file with same prefix in current directory.  
Input: userInput memory allocation (pass-by-reference)
Output: TRUE if input found (int), points userInput to value string 
Code adapted from 3_5_stat_example 
*/
int findFilenameFromuserInput(char *userInput)
{
  printf("%s", FILENAME_PROMPT);
  scanf("%s", userInput);

  // Validate userInput is CSV file
  if (!filenameContainsExtension(userInput, CSV_FILE_EXTENSION))
  {
    // Notify of invalid extension
    printf(INVALID_FILENAME_MSG, userInput);
    return FALSE;
  }

  DIR *currDir = opendir(".");
  struct dirent *dirPtr;
  struct stat dirMetaData;

  while ((dirPtr = readdir(currDir)) != NULL)
  {
    // If current filename matches user input
    if (strcmp(dirPtr->d_name, userInput) == 0)
    {
      closedir(currDir);
      return processFile(userInput);
    }
  }
  printFileNotFoundMessage(userInput);
  closedir(currDir);
  free(dirPtr);
  return FALSE;
}

/*
Creates a new directory by concatenating ONID + movies + 
Input: dirname (by-reference)
Output: TRUE if folder is successfully created
Refence: Code adapted from 3_5_stat_example and https://www.geeksforgeeks.org/sprintf-in-c/
*/

int createFolderWithRandom(char *dirname)
{
  // Crate random
  int randomNum = createRandomNumberInRange();

  // Concatenate. Code adapted from https://www.geeksforgeeks.org/sprintf-in-c/
  sprintf(dirname, "%s.%s.%d", ONID_ID_STR, MOVIE_STR, randomNum);

  // Create dir. Code adapted from 3_5_stat_example
  int status = !mkdir(dirname, DIR_PERMISSIONS);

  if (status)
    printf(DIRECTORY_CREATION_SUCCESS_MSG, dirname);
  return status;
}

/*
Function to create a directory, file per movie year with their titles
Input: filename (string)
Output: TRUE for successful file creation, FALSE for failure
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
    return FALSE;
  }

  // Create array of unique movie years
  int yearSize = 0;
  int *uniqueMovieYears = createUniqueMovieYearsArr(movieList, &yearSize);

  for (int yearIdx = 0; yearIdx < yearSize; yearIdx++)
    createFileWithMoviesPerYear(movieList, uniqueMovieYears[yearIdx], dirname);

  freeMovieList(movieList);
  free(dirname);
  return TRUE;
}

/*
Function to manage user interaction for file creation
Input: filename (string) -> memory allocation by reference
Output: TRUE for successful file creation, FALSE for failure
*/
int processFileMenu(char *filename)
{
  int option;
  do
  {
    option = promptUserForFileProcessingMenuOption();
    switch (option)
    {
    // 1 - pick the largest file
    case 1:
      if (findLargestFileFromPrefix(filename))
        return EXIT_SUCCESS;
      break;
    // 2 - pick the smallest file
    case 2:
      if (findSmallestFileFromPrefix(filename))
        return EXIT_SUCCESS;
      break;
    // 3 - to specify the name of a file
    case 3:
      if (findFilenameFromuserInput(filename))
        return EXIT_SUCCESS;
      break;
    // Other - Print bad input message
    default:
      printWrongOptionMessage();
    }
  } while (TRUE);
  return 0;
}