#! /bin/bash

# Cleans previously compiled files and created folders
function preCompileClean() {
  rm -rf movies_by_year constants.o fileHandlers.o movieList.o lib_movies.a turatip.movies.*
}

# Cleans space of temporary compile files
function postCompileClean() {
  rm -f constants.o fileHandlers.o movieList.o lib_movies.a
}

function generateModuleObjectsAndArchive() {
  # Create precompiled objects
  gcc --std=gnu99 -c constants/constants.c
  gcc --std=gnu99 -c fileHandlers/fileHandlers.c
  gcc --std=gnu99 -c movieList/movieList.c

  # Creates archive with objects
  ar -r lib_movies.a constants.o fileHandlers.o movieList.o
}

# Compiles main
function compileMainAndArchive() {
  gcc --std=gnu99 -o movies_by_year main.c lib_movies.a
}

function main() {
  # Pre cleaning, removes leftovers from previous runs
  preCompileClean

  # Compilation step
  generateModuleObjectsAndArchive
  compileMainAndArchive

  # Pre cleaning to eliminate temporary files
  postCompileClean

  # Handles parameters to execute.
  # Param e -> triggers executable
  while getopts "e" flag; do
    case $flag in
    e) ./movies_by_year ;;
    v) valgrind ./movies_by_year ;;
    esac
    shift
  done
}

# Execute this script passing params to main
main "$@"
