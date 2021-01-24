#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
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
Output: 
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
Output: 
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