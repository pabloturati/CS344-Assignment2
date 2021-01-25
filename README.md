# CS344-Assignment2
CS344-Assignment 2 Files & Directories\
Author: Pablo Turati - turatip@oregonstate.edu\
Licence: MIT. Refer to `LICENSE` for details.

## Project Description

This application provides the following functionality

- Reads all comma-separed-value files in the root of the document that starts with the prefix `movies_`. 
- Finds the smallest, the largest or any .cvs file specifically requested by the user.
- For each request, creates a folder with a random number
- In that new directory, it creates individual files with the names of movies per year.

## Compile instructions

This project uses GNU99 compile standards for building the executable.

### Option 1.  Using compile script

This application includes a bash script to build and deploy the runner (compileApp.sh).  To use it, make sure that this file (compileApp.sh) has execution persmissions by running:

`$ chmod +x compileApp.sh`

You may execute the compile instructions by running from the project root:

`$ ./compileApp.sh`

This will generate a `movies_by_year` exectable file as output. Refer to the next section on how to run the application and pass parameters.

### Option 2.  Individual commands

Refer to the contents of `compileApp.sh` for a detailed command list on how to manually compile using command line.  Notice that this project was designed to be compiled with GNU99 standards.

### Option 3.  Compile and run in sigle step

`compileApp.sh` accepts the flag `-e`, in which case it will compile, generate the executable and immediately run it.  To do this run:

`$ compileApp.sh -e`

## Run procedure

Once the application executable has been created `movies_by_year`. It can be run as follows:

`$ ./movies_by_year`

To compile and run in a single step run: `$ compileApp.sh -e`
To compile and run memory leaks debugger run: `$ compileApp.sh -v`

## Input File data structure

Files used as input must be a comma-separated file (.csv) with the following structure and application data type interpretation:

 - **Movie Title** :: string
 - **Year** :: integer number
 - **Languages** :: string 
 - **Rating Value** :: floating point number

First line of the input file is expected to contain headers, therefore data reading starts from second line.
Note that for smallest and largest file functionality to work, the file name must start with the prefix `movies_`

## Additional resources

## Project File structure
```
root
├── .gitignore
├── compileApp.sh
├── main.c
├── LICENSE
├── README.md
├── constants
│   ├── constants.c
│   └── constants.h
├── movieList
│   ├── movieList.c
│   └── movieList.h
└── fileHandlers
    ├── fileHandlers.c
    └── fileHandlers.h
```

## Version control

 Link to the repository is available at [here](https://github.com/pabloturati/CS344-Assignment2).  However, due to this being an Oregon State University assignment, it will remain private and public access will become available after April, 2021.