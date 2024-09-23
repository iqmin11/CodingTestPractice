#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

int main()
{
	WSADATA wsaData;

	int iResult;

	//���� �ʱ�ȭ
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != 0)
	{
		std::cerr << "WSAStartup ����: " << iResult << std::endl;
		return 1;
	}

	std::cout << "WSAStartup ����" << std::endl;

	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ListenSocket == INVALID_SOCKET)
	{
		std::cerr << "���� ���� ���� : " << WSAGetLastError() << std::endl;
		WSACleanup();
		return 1;
	}

	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;
	service.sin_port = htons(27015);

	iResult = bind(ListenSocket, (SOCKADDR*)&service, sizeof(service));
	if (iResult == SOCKET_ERROR)
	{
		std::cerr << "���ε� ����: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR)
	{
		std::cerr << "���� ����: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	std::cout << "Ŭ���̾�Ʈ ���� ��� ��..." << std::endl;

	SOCKET ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET)
	{
		std::cerr << "���� ���� ����: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	std::cout << "Ŭ���̾�Ʈ ���� ������" << std::endl;


	char recvbuf[512];
	int recvbuflen = 512;

	while (true)
	{
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0)
		{
			std::cout << "Ŭ���̾�Ʈ�κ��� ������ ����: " << std::string(recvbuf, iResult) << std::endl;

			std::string sendbuf;
			std::cout << "����: ";
			std::getline(std::cin, sendbuf);

			iResult = send(ClientSocket, sendbuf.c_str(), (int)sendbuf.length(), 0);
			if (iResult == SOCKET_ERROR)
			{
				std::cerr << "������ �۽� ����: " << WSAGetLastError() << std::endl;
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
		}
		else if (iResult == 0)
		{
			std::cout << "������ ����Ǿ����ϴ�." << std::endl;
			break;
		}
		else
		{
			std::cerr << "������ ���� ����: " << WSAGetLastError() << std::endl;
			break;
		}
	}

	
	closesocket(ClientSocket);
	//���� ������
	closesocket(ListenSocket);
	WSACleanup();
	return 0;
}