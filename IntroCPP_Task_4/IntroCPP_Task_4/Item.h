#pragma once
#include "String.h"

class Item
{
public:
    virtual ~Item() {}
    virtual void Description() const = 0;
    virtual void Use() = 0;
};
