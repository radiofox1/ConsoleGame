#ifndef CASTLE_H
#define CASTLE_H

#include "Logic/Objects/immovable.h"
class Castle : public Immovable
{

public:
    Castle(string name)
        : Immovable(name){

    }
};

#endif // CASTLE_H
