#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() 
{
	// Initializing all spells for the player
	m_spells.push_back("Magic Missle,");
	m_spells.push_back("Frostbite,");
	m_spells.push_back("Lightning Bolt,");
	m_spells.push_back("Fireball,");
	m_spells.push_back("Meteor Swarm and");
	m_spells.push_back("Cure Wounds");
}

Player::~Player() {}

// To see if the player knows a spell
bool Player::FindSpell(const String& spell) const 
{
	for (const auto& s : m_spells) 
	{
		
		if (s == spell) {
			cout << "You know the spell: " << spell << endl;
			return true;
		}
	}
	
	cout << "You don't know the spell: " << spell << endl;
	return false;
}

// Prints a list showing all the initialized spells
void Player::ListSpells() const 
{
	cout << "Spells you know: ";

	for (const auto& spell : m_spells) 
	{
		cout << spell.CStr() << " ";
	}
	cout << endl;
}
