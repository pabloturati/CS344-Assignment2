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

// Input:
// Output:
// */
// char *findSmallestFile()
// {
// }
// /*

// Input:
// Output:
// */
// char *findLargestFile()
// {
// }

// Function to open a file
int findFileLargestFileFromPrefix()
{

  DIR *currDir = opendir(".");
  struct dirent *dirPtr;
  struct stat dirMetaData;

  struct file_data largest;
  largest.size = 0;

  // printf("%llu", largest.size);

  while ((dirPtr = readdir(currDir)) != NULL)
  {
    if (strMatchesPrefix(dirPtr->d_name, FILE_NAME_PREFIX))
    {
      //Get metadata for current file entry
      stat(dirPtr->d_name, &dirMetaData);
      printf("%s, %lld \n", dirPtr->d_name, dirMetaData.st_size);
      if (largest.size == -1 || dirMetaData.st_size > largest.size)
      {
        printf("Initializing with ");
        largest.name = dirPtr->d_name;
        largest.size = dirMetaData.st_size;
        printf("%s, %lld \n", largest.name, largest.size);
      }
    }
  }
  closedir(currDir);
  printf("largest is %s\n", largest.name);
  return 1;
}
