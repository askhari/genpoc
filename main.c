// include custom headers
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "individual.h"
#endif

#ifndef FITNESS_H
#define FITNESS_H
#include "fitness.h"
#endif

#define MAX_INDIVIDUALS 100
#define MAX_GENERATIONS 10000

int main(int argc, char *argv[]) {
  individual ind[MAX_INDIVIDUALS];
  float total_fitness = 0.0f;
  int generation = 0;

  printf("Number of individuals: %d\n", MAX_INDIVIDUALS);
  printf("Number of cromosoms per individual: %d\n", MAX_CROMOSOMS);
  printf("Size of a GEN: %d\n", GEN_LENGTH);

  for (int critter = 0; critter < MAX_INDIVIDUALS; critter++) {

    for (int i = 0; i < MAX_CROMOSOMS; i++) {
      // change random seed to allow different gen generation
      srand(time(NULL) - i - critter);
      for (int j = 0; j < MAX_GENS; j++) {
        ind[critter].cromosoms[i].gens[j] = generate_gen();
      }
    }

    // Calculate fitness
    calculate_fitness(&ind[critter]);
    if (ind[critter].fitness == 999.0f) {
      printf("Evolution completed!!!");
      printf("Individual number: %d\n", critter);
      for (int i = 0; i < MAX_CROMOSOMS; i++) {
        for (int j = 0; j < MAX_GENS; j++) {
          printf("Cromosom %d - Gen %d: %d\n", i, j, ind[critter].cromosoms[i].gens[j]);
        }
      }
    }
    total_fitness += ind[critter].fitness;

    printf("Individual number: %d\n", critter);
    for (int i = 0; i < MAX_CROMOSOMS; i++) {
      for (int j = 0; j < MAX_GENS; j++) {
        printf("Cromosom %d - Gen %d: %d\n", i, j, ind[critter].cromosoms[i].gens[j]);
      }
    }
/*
  printf("Generating mutations...\n");
    for (int i = 0; i < MAX_CROMOSOMS; i++) {
      // change random seed to allow different gen generation
      for (int j = 0; j < MAX_GENS; j++) {
        ind[critter].cromosoms[i].gens[j] = mutate(ind[critter].cromosoms[i].gens[j]);
      }
    }
    for (int i = 0; i < MAX_CROMOSOMS; i++) {
      for (int j = 0; j < MAX_GENS; j++) {
        printf("Mutated Cromosom %d - Gen %d: %d\n", i, j, ind[critter].cromosoms[i].gens[j]);
      }
    }
*/
    printf("Associated fitness: %f\n", ind[critter].fitness);
    printf("--------------------------\n");
  }

  printf("Total fitness population: %f\n", total_fitness);
  printf("\n");

  int iteration = 0;
  while (1) {
    if (iteration % 100 == 0) {
      printf("Creating new population of generation: %d...\n", generation);
    }
    individual offspring1[MAX_INDIVIDUALS];
    individual offspring2[MAX_INDIVIDUALS];

    for (int critter = 0; critter < MAX_INDIVIDUALS; critter++) {
      offspring1[critter] = choose_individual(total_fitness,ind);
      offspring2[critter] = choose_individual(total_fitness,ind);
    }

    /*
    printf("--------------------------\n");
    printf("Printing the ONEs in offspring1:)\n");
    for (int critter = 0; critter < MAX_INDIVIDUALS; critter++) {
      printf("Offspring1 number: %d\n", critter);
      for (int i = 0; i < MAX_CROMOSOMS; i++) {
        for (int j = 0; j < MAX_GENS; j++) {
          printf("Cromosom %d - Gen %d: %d\n", i, j, offspring1[critter].cromosoms[i].gens[j]);
        }
      }

      printf("Associated fitness: %f\n", offspring1[critter].fitness);
      printf("--------------------------\n");
    }
    printf("--------------------------\n");
    printf("Printing the ONEs in offspring2:)\n");
    for (int critter = 0; critter < MAX_INDIVIDUALS; critter++) {
      printf("Offspring number: %d\n", critter);
      for (int i = 0; i < MAX_CROMOSOMS; i++) {
        for (int j = 0; j < MAX_GENS; j++) {
          printf("Cromosom %d - Gen %d: %d\n", i, j, offspring2[critter].cromosoms[i].gens[j]);
        }
      }

      printf("Associated fitness: %f\n", offspring2[critter].fitness);
      printf("--------------------------\n");
    }
*/
    create_new_population(ind,offspring1,offspring2);

    for (int critter = 0; critter < MAX_INDIVIDUALS; critter++) {

      // Calculate fitness
      calculate_fitness(&ind[critter]);
      if (ind[critter].fitness == 999.0f) {
        printf("Evolution completed!!!");
        printf("Individual number: %d\n", critter);
        for (int i = 0; i < MAX_CROMOSOMS; i++) {
          for (int j = 0; j < MAX_GENS; j++) {
            printf("Cromosom %d - Gen %d: %d\n", i, j, ind[critter].cromosoms[i].gens[j]);
          }
        }
        printf("Generation: %d...\n", generation);
        get_fitness(&ind[critter]);
        return 0;
      }
      total_fitness += ind[critter].fitness;
/*
      printf("Individual number: %d\n", critter);
      for (int i = 0; i < MAX_CROMOSOMS; i++) {
        for (int j = 0; j < MAX_GENS; j++) {
          printf("Cromosom %d - Gen %d: %d\n", i, j, ind[critter].cromosoms[i].gens[j]);
        }
      }
    */
    }
    generation++;
    iteration++;
  }
  return 0;
}
