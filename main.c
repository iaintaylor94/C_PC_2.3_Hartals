#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/errno.h>

// Declare input file handles
FILE *gInputFile;

// Declare Functions
void usage (char *);

int getNumberOfCases(FILE*);

int main(int argc, char *argv[]) {
  /*-------------------------------FILE INITIALIZATION START-----------------------------*/
  if (argc != 2) usage (argv[0]);

  if (NULL == (gInputFile = fopen(argv[1], "r"))) {
    fprintf (stderr, "inputFile: %s: %s\n", argv[1], strerror(errno));
    exit (EXIT_FAILURE);
  }
  else {
      fprintf (stderr, "%s opened for reading.\n" , argv[1]);
    }
  /*-------------------------------FILE INITIALIZATION END--------------------------------*/

  /*--------------------------------MAIN PROGRAM START------------------------------------*/

  int numberOfCases = getNumberOfCases(gInputFile);
  printf ("%d", numberOfCases);


  /*--------------------------------MAIN PROGRAM END--------------------------------------*/

  /*--------------------------------FILE CLEANUP START------------------------------------*/
  fclose (gInputFile);
  /*--------------------------------FILE CLEANUP END--------------------------------------*/
  return 0;
}

// Define Functions
void usage (char *cmd) {
  fprintf (stderr, "usage: %s inputFileName\n", cmd);
  exit (EXIT_SUCCESS);
}

int getNumberOfCases(FILE* fp) {
  char inputLine [81];
  int nc = 0;
  fgets (inputLine, 81, gInputFile);
  sscanf (inputLine, "%d", &nc);
  return (nc);
}