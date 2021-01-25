#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "fileHandlers.h"
#include "../constants/constants.h"

struct file_data
{
  off_t size;
  char *name;
};

/*
The program finds the largest file with the extension csv in the current directory
whose name starts with the prefix movies_ and automatically process it.
*/

/*
Returns largest file with same prefix in current directory.  
Input: none
Output: name of smallest file in current directory (string)
Code adapted from 3_5_stat_example 
*/
char *findSmallestFileFromPrefix()
{
  DIR *currDir = opendir(".");
  struct dirent *dirPtr;
  struct stat dirMetaData;

  struct file_data smallest;

  //Sets initial smallest size to 0 to default smallest to first file
  smallest.size = 0;

  while ((dirPtr = readdir(currDir)) != NULL)
  {
    if (strMatchesPrefix(dirPtr->d_name, FILE_NAME_PREFIX))
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
  return smallest.name;
}

/*
Returns largest file with same prefix in current directory.  
Input: none
Output: name of largest file in current directory (string)
Code adapted from 3_5_stat_example 
*/
char *findLargestFileFromPrefix()
{
  DIR *currDir = opendir(".");
  struct dirent *dirPtr;
  struct stat dirMetaData;

  struct file_data largest;

  //Sets initial largest size to 0 to default largest to first file
  largest.size = 0;

  while ((dirPtr = readdir(currDir)) != NULL)
  {
    if (strMatchesPrefix(dirPtr->d_name, FILE_NAME_PREFIX))
    {
      //Get metadata for current file entry
      stat(dirPtr->d_name, &dirMetaData);
      if (largest.size == 0 || dirMetaData.st_size > largest.size)
      {
        largest.name = dirPtr->d_name;
        largest.size = dirMetaData.st_size;
      }
    }
  }
  closedir(currDir);
  return largest.name;
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

  DIR *currDir = opendir(".");
  struct dirent *dirPtr;
  struct stat dirMetaData;

  while ((dirPtr = readdir(currDir)) != NULL)
  {
    if (strcmp(dirPtr->d_name, userInput) == 0)
    {
      closedir(currDir);
      // free(dirPtr);
      return TRUE;
    }
  }
  printFileNotFoundMessage(userInput);
  closedir(currDir);
  // free(dirPtr);
  return FALSE;
}

int mkdir(const char *pathname, mode_t mode);

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
