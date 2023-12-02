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

int printDaysLostWorking(int[], int, int);
int calculateDaysLost(int[], int, int);

void processCase (void);

int main(int argc, char *argv[]) {
  /*-------------------------------FILE INITIALIZATION START-----------------------------*/
  if (argc != 2) usage (argv[0]);

  if (NULL == (gInputFile = fopen(argv[1], "r"))) {
    fprintf (stderr, "inputFile: %s: %s\n", argv[1], strerror(errno));
    exit (EXIT_FAILURE);
  }
  else {
//      fprintf (stderr, "%s opened for reading.\n" , argv[1]);
    }
  /*-------------------------------FILE INITIALIZATION END--------------------------------*/

  /*--------------------------------MAIN PROGRAM START------------------------------------*/

  int numberOfCases = getNumberOfCases();
//  printf ("number of cases: %d\n", numberOfCases);

  for (int i = 0; i < numberOfCases; i++) {
    processCase();
  }


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

void printDay (int day) {
  switch (day % 7) {
    case 0:
      printf ("Sat ");
      break;
    case 1:
      printf ("Sun ");
      break;
    case 2:
      printf ("Mon ");
      break;
    case 3:
      printf ("Tue ");
      break;
    case 4:
      printf ("Wed ");
      break;
    case 5:
      printf ("Thu ");
      break;
    case 6:
      printf ("Fri ");
      break;
    default:
      printf ("invalid day\n");
     break;
  }
}

int printDaysLostWorking(int hartalNumbers[], int numParties, int numDays) {
  int daysLost = 0;
  printf ("ID  Day Hartal\n");
  printf ("--- --- ------\n");
  for (int i = 1; i < numDays + 1; i++) {
    printf ("%3d ", i);
    printDay (i);
    if (i % 7 == 6) { // no hartal on Friday
      printf ("\n");
      continue; 
    }
    else if (i % 7 == 0) { // no hartal on Saturday
      printf ("\n");
      continue; 
    }
    else {
      for (int j = 0; j < numParties; j++) {
        if (i % hartalNumbers[j] == 0) {
          daysLost++;
          printf ("     x");
          break;
        }
      }
      printf ("\n");
    }
  }
  return daysLost;
}

int calculateDaysLost(int hartalNumbers[], int numParties, int numDays) {
  int daysLost = 0;
  for (int i = 1; i < numDays + 1; i++) {
    if (i % 7 == 6) { // no hartal on Friday
      continue; 
    }
    else if (i % 7 == 0) { // no hartal on Saturday
      continue; 
    }
    else {
      for (int j = 0; j < numParties; j++) {
        if (i % hartalNumbers[j] == 0) {
          daysLost++;
          break;
        }
      }
    }
  }
  return daysLost;
}

void processCase (void) {
  int numberOfDays = getNumberOfDays();
//  printf ("number of days %d\n", numberOfDays);
  int numberOfParties = getNumberOfParties();
//  printf ("number of parties %d\n", numberOfParties);

  int hartalNumbers[numberOfParties];
  getHartalNumbers(hartalNumbers, numberOfParties);
//  printHartalNumbers(hartalNumbers, numberOfParties);

  int daysLost = calculateDaysLost(hartalNumbers, numberOfParties, numberOfDays);
  printf ("%d\n", daysLost);
}