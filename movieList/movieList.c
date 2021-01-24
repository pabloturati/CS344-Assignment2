#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movieList.h"
#include "../constants/constants.h"

/* 
Creates and returns pointer to a link list with struct movie 
objects based on each line of a cvs file input with several rows.
Input: filepath (string)
Output: head (struct movie *)
*/
struct movie *createMovieList(char *filePath)
{
  // Opens file for reading
  FILE *movieFile = fopen(filePath, "r");
  char *currLine = NULL;
  size_t len = 0;
  ssize_t nread;
  char *token;

  struct movie *head = NULL;
  struct movie *tail = NULL;

  // Read and ignore first line (header line)
  getline(&currLine, &len, movieFile);

  // Parse each line to linkedlist objects
  while ((nread = getline(&currLine, &len, movieFile)) != -1)
  {
    struct movie *newNode = createMovieNode(currLine);

    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }
  free(currLine);
  return head;
}

/* 
Creates and returns pointer to a struct movie object 
objects based on a single cvs file line.
Input: currLine (string)
Output: head (struct movie *)
*/
struct movie *createMovieNode(char *currLine)
{
  struct movie *currMovie = malloc(sizeof(struct movie));

  // Pointer to curr strtok_r position
  char *rest;

  // Set title
  char *token = strtok_r(currLine, ",", &rest);
  currMovie->title = calloc(strlen(token) + 1, sizeof(char));
  strcpy(currMovie->title, token);

  // Set year
  token = strtok_r(NULL, ",", &rest);
  currMovie->year = atoi(token);

  // Set languages
  token = strtok_r(NULL, ",", &rest);
  currMovie->languages = calloc(strlen(token) + 1, sizeof(char));
  strcpy(currMovie->languages, token);

  // Set rating
  token = strtok_r(NULL, ",", &rest);
  currMovie->rating = strtof(token, NULL);

  // Set next movie ptr
  currMovie->next = NULL;
  return currMovie;
}

/* 
Creates an integer array with unique movie years.
Input: list head (struct movie *), size (int passed by reference)
Output: returns uniqueYearArr (int array *), writes on 'size'
*/
int *createUniqueMovieYearsArr(struct movie *head, int *size)
{
  // Pointer to set (no duplicate values)
  int *uniqueYearArr = (int *)calloc(MAX_MOVIE_YEARS, sizeof(int));
  struct movie *curr = head;
  // Traverse list to find years that are not in the set
  while (curr != NULL)
  {
    // If not already in the set, add it. Else continue.
    if (!arrayContainsValue(uniqueYearArr, *size, curr->year))
    {
      uniqueYearArr[*size] = curr->year;
      ++(*size);
    }
    curr = curr->next;
  }
  // Resizes array to content to reclaims unused memory
  uniqueYearArr = (int *)realloc(uniqueYearArr, *size * sizeof(int));
  return uniqueYearArr;
}

/* 
Prints highest rated movie to std out (screen) in format:
YEAR RATING (single decimal floating point) TITLE
Input: list head (struct movie *), uniqueYears(array of int), arrSize (int)
Output: (void) prints to stdout (screen).
*/
void printMoviesWithHighestRatingsPerYear(struct movie *head, int *uniqueYears, int arrSize)
{
  for (int i = 0; i < arrSize; i++)
  {
    struct movie *curr = head;
    struct movie *highest = NULL;
    while (curr)
    {
      if (curr->year == uniqueYears[i])
      {
        if (highest == NULL)
        {
          highest = curr;
        }
        else if (curr->rating > highest->rating)
        {
          highest = curr;
        }
      }
      curr = curr->next;
    }
    printf("%d %.1f %s\n", uniqueYears[i], highest->rating, highest->title);
  }
  printf("\n");
}

/* 
Prints to stdout (screen) movies that contain (exact match) the selected language. 
Filter operation is done by substring match.  Print format is:  YEAR TITLE
Input: list head (struct movie *), language (string)
Output: (void) prints to stdout (screen).
*/
void printMoviesOfCertainLanguage(struct movie *head, char *language)
{
  struct movie *curr = head;
  int count = 0;
  while (curr)
  {
    char *ptrToStrMatch = strstr(curr->languages, language);
    if (ptrToStrMatch != NULL)
    {
      printf("%d %s\n", curr->year, curr->title);
      ++count;
    }
    curr = curr->next;
  }
  if (count == 0)
  {
    printf(LANGUAGE_EMPTY_RECORDS_MSG, language);
  }
  else
  {
    printf(LANGUAGE_RECORDS_MSG, count, language);
  }
}

/* 
Filter operation is done by substring match.  Print format is:  YEAR TITLE
Input: list head (struct movie *), year (string)
Output: (void) prints to stdout (screen).
*/
void filteMoviesByYear(struct movie *head, unsigned short year)
{
  size_t count = 0;
  struct movie *curr = head;
  while (curr != NULL)
  {
    if (curr->year == year)
    {
      printf("%s\n", curr->title);
      ++count;
    }
    curr = curr->next;
  }
  if (count == 0)
  {
    printf(NO_YEAR_RESULT_MSG, year);
  }
  else
  {
    printf(TOTAL_RECORDS_FOUND_IN_YEAR, count, year);
  }
}

/* 
Method that releases memory allocated for the movie linked list
Input: list head (struct movie *)
Output: (void)
*/
void freeMovieList(struct movie *list)
{
  struct movie *curr = list;
  while (curr != NULL)
  {
    struct movie *next = curr->next;
    //Releases movie fields
    free(curr->title);
    free(curr->languages);
    //Releases movie object
    free(curr);
    curr = next;
  }
}

/* 
Returns size in integer number of a linked list
Input: list head (struct movie *)
Output: listLenght (integer). 0 for empty.
*/
int movieListHasContent(struct movie *list, char *fileName)
{
  size_t listLength = 0;
  //Counts list objects until last one
  while (list != NULL)
  {
    list = list->next;
    ++listLength;
  }
  //Print result to screen
  if (listLength > 0)
  {
    printf(LIST_CREATION_SUCCESS_MSG, fileName, listLength);
  }
  else
  {
    printf(LIST_CREATION_SUCCESS_EMPTY_MSG, fileName, listLength);
  }
  return listLength;
}