#include <math.h>

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "individual.h"
#endif

// Mask to define a operation to be done (+,-,*,/)
#define OPERATION_MASK 0x000F
#define TARGET_VALUE 42
//#define RANDOM_NUM ((float)rand()/(RAND_MAX))
#define MUTATION_RATE 0.005
#define SELECT_CUT 0.7

/* Calculate fitness */
void calculate_fitness(individual *ind) {

  float result = 0.0;
  float fitness = 0.0;
  // First gen defines other gens operations
//  printf("Calculating fitness...\n");
  for (int cromo = 0; cromo < MAX_CROMOSOMS; cromo++) {
    gen op = ind->cromosoms[cromo].gens[0];
//    printf("Operations GEN: %d\n", op);

    for (int j = 1; j <= MATH_SKILL_GEN; j++) {
      if (j == 1) {
          result = (float)ind->cromosoms[cromo].gens[j];
      } else {
        switch ((op & OPERATION_MASK) % 4) {
          case 0:
//            printf("Add: %d\n", ind->cromosoms[cromo].gens[j]);
            result += (float)ind->cromosoms[cromo].gens[j];
            break;

          case 1:
//            printf("Substract: %d\n", ind->cromosoms[cromo].gens[j]);
            result -= (float)ind->cromosoms[cromo].gens[j];
            break;

          case 2:
//            printf("Multiply: %d\n", ind->cromosoms[cromo].gens[j]);
            result *= (float)ind->cromosoms[cromo].gens[j];
            break;

          case 3:
//            printf("Divide: %d\n", ind->cromosoms[cromo].gens[j]);
            result /= (float)ind->cromosoms[cromo].gens[j];
            break;

        }
      }
      op >>= MATH_SKILL_GEN;
//      printf("Next operation: %d\n", op);
    }
  } 

	if (result == (float)TARGET_VALUE) {
		ind->fitness = 999.0f;
  } else {
    //printf("Final fitness result: %f\n", result);
		ind->fitness = 1/fabsf((float)(TARGET_VALUE - result));
  }

  return;
}

/*
individual choose_parent(individual population) {

  individual choosen;

  for (int i = 0; i < MAX_INDIVIDUAL; i++) {
    if (RANDOM_NUM < SELECT_CUT) {

    } 
  }

  return choosen;
}
*/

void get_fitness(individual *ind) {

  float result = 0.0;
  float fitness = 0.0;
  // First gen defines other gens operations
//  printf("Calculating fitness...\n");
  for (int cromo = 0; cromo < MAX_CROMOSOMS; cromo++) {
    gen op = ind->cromosoms[cromo].gens[0];
    printf("Operations GEN: %d\n", op);

    for (int j = 1; j <= MATH_SKILL_GEN; j++) {
      if (j == 1) {
          result = (float)ind->cromosoms[cromo].gens[j];
      } else {
        switch ((op & OPERATION_MASK) % 4) {
          case 0:
            printf("Add: %d\n", ind->cromosoms[cromo].gens[j]);
            result += (float)ind->cromosoms[cromo].gens[j];
            break;

          case 1:
            printf("Substract: %d\n", ind->cromosoms[cromo].gens[j]);
            result -= (float)ind->cromosoms[cromo].gens[j];
            break;

          case 2:
            printf("Multiply: %d\n", ind->cromosoms[cromo].gens[j]);
            result *= (float)ind->cromosoms[cromo].gens[j];
            break;

          case 3:
            printf("Divide: %d\n", ind->cromosoms[cromo].gens[j]);
            result /= (float)ind->cromosoms[cromo].gens[j];
            break;

        }
      }
      op >>= MATH_SKILL_GEN;
      printf("Next operation: %d\n", op);
    }
  } 

  printf("Final fitness result: %f\n", result);
  return;
}
