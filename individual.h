#ifndef CROMOSOM_H
#define CROMOSOM_H
#include "cromosom.h"
#endif

#define MAX_INDIVIDUAL 100

typedef struct individual {
  cromosom cromosoms[MAX_CROMOSOMS];
  float fitness;
} individual;

individual crossover(individual *parent, individual *mother) {
  individual descent;

  descent.fitness = 0.0f;

  mix_cromosoms(parent->cromosoms,mother->cromosoms,descent.cromosoms);

  return descent;
}

individual choose_individual(float total_fitness, individual *first) {
  float fitness = 0.0f;
  float slice = (float)(RANDOM_NUM * total_fitness);

  while(1) {
    for (int i = 0; i < MAX_INDIVIDUAL; i++) {
      fitness += first[i].fitness;
      if (fitness >= slice) {
        return first[i];
      }
    }
  }
}

void create_new_population(individual *ind, individual *offspring1, individual *offspring2) {
  for (int critter = 0; critter < MAX_INDIVIDUAL; critter++) {
    ind[critter].fitness = 0.0f;
    for (int i = 0; i < MAX_CROMOSOMS; i++) {
      // change random seed to allow different gen generation
//      srand(time(NULL) - i - critter);
      for (int j = 0; j < MAX_GENS; j++) {
        srand(time(NULL) - i - j - critter);
        gen gen_a = offspring1[critter].cromosoms[i].gens[j];
        gen gen_b = offspring2[critter].cromosoms[i].gens[j];
        ind[critter].cromosoms[i].gens[j] = mix_gens(gen_a,gen_b);
      }
    }
  }
  return;
}
