#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/errno.h>

// Declare input file handles
FILE *gInputFile;

// Declare Functions
void usage (char *);

int getInt(void);
int getNumberOfCases(void);
int getNumberOfDays(void);
int getNumberOfParties(void);

void getHartalNumbers(int[], int);
void printHartalNumbers(int[], int);

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

  int numberOfCases = getNumberOfCases();
  printf ("number of cases: %d\n", numberOfCases);
  int numberOfDays = getNumberOfDays();
  printf ("number of days %d\n", numberOfDays);
  int numberOfParties = getNumberOfParties();
  printf ("number of parties %d\n", numberOfParties);

  int hartalNumbers[numberOfParties];
  getHartalNumbers(hartalNumbers, numberOfParties);
  printHartalNumbers(hartalNumbers, numberOfParties);


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

int getInt() {
  char inputLine [81];
  int returnInt = 0;
  fgets (inputLine, 81, gInputFile);
  sscanf (inputLine, "%d", &returnInt);
  return (returnInt);
}

int getNumberOfCases(void) {
  return (getInt());
}
int getNumberOfDays(void) {
  return getInt();
}
int getNumberOfParties(void) {
  return getInt();
}
void getHartalNumbers(int hartalNumbers[], int numberOfParties) {
  for (int i = 0; i < numberOfParties; i++) {
    hartalNumbers[i] = getInt();
  }
}
void printHartalNumbers(int hartalNumbers[], int numberOfParties) {
  printf ("Hartal array: {");
  for (int i = 0; i < numberOfParties; i++) {
    printf (" %d", hartalNumbers[i]);
  }
  printf (" }\n");
}