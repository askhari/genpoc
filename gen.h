#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GEN_BITS 8
#define GEN_LENGTH ((8*sizeof(int))-1)
#define MAX_GENS 5
#define GEN_BASE 1 << GEN_BITS

// Returns a random num between 0 and 1
#define RANDOM_NUM ((float)rand()/(RAND_MAX))
// Define number of genes for math skill
#define MATH_SKILL_GEN 4
//#define NUM_OPERATIONS (MATH_SKILL_GEN - 1)
//
// Returns a random bit mask
#define RANDOM_MUT 1 <<	((int)rand() % GEN_LENGTH)
#define RANDOM_GEN (int)rand()

typedef int gen;

/* Generate a new gen */
gen generate_gen() {
  return RANDOM_GEN;
}

/* Mutates a gen */
gen mutate(gen mgen) {
  // defines which gen to mutate.
//  srand(mgen);
  gen mutagen = RANDOM_MUT;

//  printf("Mutagen defined to: %d\n", mutagen);
  return mgen^mutagen;
}

gen mix_gens(gen gen_a, gen gen_b) {
  gen mask = 0;
  mask = ~mask;
  gen top_mask = mask << GEN_LENGTH;
  gen bottom_mask = ~top_mask;
  gen new_gen = ((gen_a & top_mask) | (gen_b & bottom_mask));
  new_gen = mutate(new_gen);
/*  
  printf("Mask: %d\n", mask);
  printf("Top Mask: %d\n", top_mask);
  printf("Bottom Mask: %d\n", bottom_mask);
*/
//  return ((gen_a & top_mask) | (gen_b & bottom_mask));
  return new_gen;
}
