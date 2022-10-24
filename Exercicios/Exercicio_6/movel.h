#ifndef MOVEL_H
#define MOVEL_H

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

#define MOVEL 0

typedef struct Movel tMovel;

tMovel *CriaMovel();

void ImprimeMovel(tMovel *movel);

#endif