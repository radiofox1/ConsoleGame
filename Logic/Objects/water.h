#ifndef WATER_H
#define WATER_H

#include "Logic/Objects/immovable.h"

class Water : public Immovable
{
public:
    Water(string name)
        : Immovable(name) {}
};

#endif // WATER_H
