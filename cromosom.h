#ifndef GEN_H
#define GEN_H
#include "gen.h"
#endif

#define MAX_CROMOSOMS 1
// #define MAX_GENS 256

typedef struct cromosom {
  gen gens[MAX_GENS];
} cromosom;

void mix_cromosoms(cromosom *father, cromosom *mother, cromosom *descent) {
  return;
}
