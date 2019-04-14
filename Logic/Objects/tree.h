#ifndef TREE_H
#define TREE_H

#include "Logic/Objects/immovable.h"
class Tree : public Immovable
{
public:
Tree(string name)
        : Immovable(name) {}
};

#endif // TREE_H
