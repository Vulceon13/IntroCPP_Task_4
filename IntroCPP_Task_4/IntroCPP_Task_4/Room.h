#pragma once
#include "Item.h"
#include "String.h"


class Room
{
public:
    Room();
    Room(const char* description);
    ~Room();
    void Description() const;
    Item* GetItem() const;
    void SetItem(Item* newItem);

private:
    String description;
    Item* item;
};
