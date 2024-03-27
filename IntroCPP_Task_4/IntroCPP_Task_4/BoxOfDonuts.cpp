#include "BoxOfDonuts.h"
#include <iostream>
using namespace std;

BoxOfDonuts::BoxOfDonuts() : m_count(12) {} // Number of donuts in the box

BoxOfDonuts::~BoxOfDonuts() {}

// Printing a description for 'BoxOfDonuts'
void BoxOfDonuts::Description() const
{
    cout << "A box of donuts with " << m_count << " donuts remaining." << endl; 
}

// This is so the player can interact with the item 'BoxOfDonuts'
void BoxOfDonuts::Use() 
{
    if (m_count > 0)
    {
        cout << "You eat one of the donuts in the box." << endl;
        m_count--;
    }
    else
    {
        cout << "Unfortunately, you have eaten all the donuts." << endl;
    }
}
