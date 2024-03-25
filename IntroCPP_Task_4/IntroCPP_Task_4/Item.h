#pragma once
#include "String.h"

class Item {
public:
    virtual ~Item() { } // destructor for proper cleanup
    virtual String Description() const = 0; // Gives items descriptions
    virtual void Use() = 0; // used for usage of item
};