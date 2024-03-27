#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat() : m_purring(false) {}

Cat::~Cat() {}

// Giving a description for the item 'Cat'
void Cat::Description() const
{
    cout << "A cat, currently ";

    if (m_purring)
        cout << "purring.";
    else
        cout << "not purring.";

   cout << endl;
}

// This is used to interact with item 'Cat' 
void Cat::Use()
{
    m_purring = !m_purring;

    if (m_purring)
        cout << "The cat starts purring, how cute!";
    else
        cout << "The cat stopped purring.";

    cout << endl;
}