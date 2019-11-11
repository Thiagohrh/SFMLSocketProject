#include "NetworkManager.h"

NetworkManager::NetworkManager()
{
	IPAdress = sf::IpAddress::getLocalAddress();
	socket.setBlocking(false);
}

NetworkManager::~NetworkManager()
{
}

void NetworkManager::SetIfServer(bool isServer)
{
	if (isServer)
	{
		this->isServer = isServer;
		listener.listen(2000);
		listener.accept(socket);
		return;
	}
	socket.connect(IPAdress, 2000);
}

sf::IpAddress NetworkManager::GetIpAdress()
{
	return IPAdress;
}
