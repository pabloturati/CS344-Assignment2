#ifndef MOVIE_LIST
#define MOVIE_LIST

struct movie
{
  char *title;
  int year;
  char *languages;
  float rating;
  struct movie *next;
};

struct movie *createMovieList(char *);
struct movie *createMovieNode(char *);
int *createUniqueMovieYearsArr(struct movie *, int *);
void printMoviesWithHighestRatingsPerYear(struct movie *, int *, int);
void filteMoviesByYear(struct movie *, unsigned short);
void printMoviesOfCertainLanguage(struct movie *, char *language);
int movieListHasContent(struct movie *, char *);
void freeMovieList(struct movie *);

#endif