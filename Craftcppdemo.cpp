// Craftcppdemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MinecraftSocket.h"
#include "OpenGLRenderer.h"
#include <thread>
#include "BlockRegistry.h"

using namespace std;


void networkThread() {
	MinecraftSocket socket;
	socket.connectToServer("DevClient", "DanielLerchDell", 25565);
}

int main()
{
	cout << "> CRAFT++ Minecraft Client <" << endl;
	cout << "(c) 2018 Twometer" << endl << endl;

	BlockRegistry::initialize();

	OpenGLRenderer renderer;
	thread thread(&networkThread);
	renderer.start();


	cout << "Press any key to exit ..." << endl;
	string line;
	getline(cin, line);
    return 0;
}

