#pragma once
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

class NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();
	void SetIfServer(bool isServer);

	sf::IpAddress GetIpAdress();
	sf::TcpSocket* GetSocket() { return &socket; };
private:
	int acessPort;
	sf::IpAddress IPAdress;
	sf::TcpSocket socket;
	char connectionType;
	sf::TcpListener listener;
	bool isServer = false;
};

