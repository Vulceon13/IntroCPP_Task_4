#pragma once
#include "String.h"
#include <list>
using namespace std;

class Player
{
public:
	Player();
	~Player();
	bool FindSpell(const String& spell) const;
	void ListSpells() const;

private:
	list<String> m_spells;
};

