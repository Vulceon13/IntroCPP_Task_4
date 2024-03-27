#include "Lamp.h"
#include <iostream>
using namespace std;

Lamp::Lamp() : m_turnedOn(false) {}

Lamp::~Lamp() {}

// Giving a description for the item 'Lamp'
void Lamp::Description() const
{
    cout << "A lamp, currently ";

    if (m_turnedOn)
        cout << "turned on.";
    else
        cout << "turned off.";

   cout << endl;
}


// This is used to interact with item 'Lamp'
void Lamp::Use()
{
    m_turnedOn = !m_turnedOn;
    if (m_turnedOn)
        cout << "You turn on the lamp." << endl;
    else
       cout << "You turn off the lamp." << endl;
}