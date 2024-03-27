#pragma once
#include "Player.h"
#include "Room.h"

class Game
{
public:
	Game();
	~Game();
	void Run();
	void Move(const String& direction);
	void UseItem();

private:
	Room** m_rooms;
	Player* m_player;
	int m_currentRow;
	int m_currentCol;
};

