#ifndef _LISTE_H_
#define _LISTE_H_

#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "point.h"

pile * kNearestNeighbours(pile *, int, point *);

pile * removePoint(pile *, point *){

pile * sortByDistance(pile*, point *);

#endif
