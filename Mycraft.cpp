// Mycraft.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ConnectionManager.h"
#include "OpenGLRenderer.h"
#include <thread>
#include "BlockRegistry.h"
#include "Title.h"

using namespace std;

int main()
{
	cout << "Initializing " << GAME_TITLE << endl;
	cout << "(c) 2018 Twometer" << endl << endl;

	BlockRegistry::initialize();

	OpenGLRenderer renderer;
	ConnectionManager::connect("DevClient", "localhost", 25565);
	renderer.start();
    return 0;
}

