#! /bin/bash

# Conditional cleanup space from previously compiled files
rm -f movies constants.o movieList.o fileHandlers.o lib_movies.a

# Create precompiled objects
gcc --std=gnu99 -c constants/constants.c
gcc --std=gnu99 -c movieList/movieList.c
gcc --std=gnu99 -c fileHandlers/fileHandlers.c

# Creates external file archive
ar -r lib_movies.a constants.o movieList.o fileHandlers.o

# Compiles main
gcc --std=gnu99 -o movies main.c lib_movies.a

# Removes temporary files
rm -f constants.o movieList.o lib_movies.a fileHandlers.o

./movies movies_sample_1.csv
