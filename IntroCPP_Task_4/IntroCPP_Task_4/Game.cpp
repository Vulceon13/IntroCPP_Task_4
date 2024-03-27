#include "BoxOfDonuts.h"
#include "Cat.h"
#include "Game.h"
#include "Item.h"
#include "Lamp.h"
#include "Player.h"
#include "Room.h" 
#include "String.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor for Game class
Game::Game() : m_player(new Player()), m_currentRow(0), m_currentCol(0)
{
    // Initialize rooms with a descriptions
    m_rooms = new Room * [2];
    for (int i = 0; i < 2; ++i)
    {
        m_rooms[i] = new Room[2]; 

        for (int j = 0; j < 2; ++j)
        {
            m_rooms[i][j] = Room(("Room " + std::to_string(i * 2 + j + 1)).c_str()); 
        }
    }

    // Set items in specific rooms
    m_rooms[0][0].SetItem(new BoxOfDonuts()); 
    m_rooms[1][1].SetItem(new Lamp()); 
    m_rooms[0][1].SetItem(new Cat()); 
}

// Destructor for Game class
Game::~Game() {
    for (int i = 0; i < 2; ++i) {
        delete[] m_rooms[i];
    }
    delete[] m_rooms;
    delete m_player;
}

// Start the game
void Game::Run() {
    cout << "Welcome to the text adventure game!" << endl;
    while (true) {
        // Display current room description
        m_rooms[m_currentRow][m_currentCol].Description();

        // Prompt for user input
        cout << "Enter a command ('north', 'south', 'east', 'west', 'use' or 'spells') or quit to exit the game: ";
        String input;
        input.ReadFromConsole().ToLower();

        // Process user input
        if (input.EqualTo("quit")) {
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        }
        else if (input.EqualTo("north")) {
            Move("North");
        }
        else if (input.EqualTo("south")) {
            Move("South");
        }
        else if (input.EqualTo("east")) {
            Move("East");
        }
        else if (input.EqualTo("west")) {
            Move("West");
        }
        else if (input.EqualTo("use")) {
            UseItem();
        }
        else if (input.EqualTo("spells")) {
            m_player->ListSpells(); 
        }
        else if (input.StartsWith("spell")) {
            
            String spellName = input.SubString(6).Trim(); 
            m_player->FindSpell(spellName); 
        }
        else {
            cout << "Invalid input. Please enter a valid direction or 'quit'." << endl;
        }
    }
}

// Move the player to a new room
void Game::Move(const String& direction) {
    
    int newRow = m_currentRow;
    int newCol = m_currentCol;
    if (direction.EqualTo("North")) {
        newRow--;
    }
    else if (direction.EqualTo("South")) {
        newRow++;
    }
    else if (direction.EqualTo("East")) {
        newCol++;
    }
    else if (direction.EqualTo("West")) {
        newCol--;
    }
    // Check if the new coordinates are valid
    if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 2) {
        m_currentRow = newRow;
        m_currentCol = newCol;
    }
    else {
        cout << "Invalid direction. Please try again." << endl;
    }
}

// Use the item in the current room
void Game::UseItem() {
    Item* currentItem = m_rooms[m_currentRow][m_currentCol].GetItem();
    if (currentItem != nullptr) {
        currentItem->Use();
    }
    else {
        cout << "There is no item in this room to use." << endl;
    }
}