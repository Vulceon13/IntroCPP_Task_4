#include "Room.h"
#include <iostream>
using namespace std;

Room::Room() : description("Empty Room"), item(nullptr) {}

Room::Room(const char* description) : description(description), item(nullptr) {}

Room::~Room()
{
    delete item;
}

// Prints description of the room and what inside
void Room::Description() const
{
    cout << "You are in " << description << endl;

    if (item != nullptr)
        item->Description();
}


// Get the item present in the room
Item* Room::GetItem() const
{
    return item;
}

// Used Set item in a room
void Room::SetItem(Item* newItem)
{
    item = newItem;
}