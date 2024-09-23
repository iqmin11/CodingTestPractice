#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

int main()
{
	WSADATA wsaData;

	int iResult;

	//소켓 초기화
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != 0)
	{
		std::cerr << "WSAStartup 실패: " << iResult << std::endl;
		return 1;
	}

	std::cout << "WSAStartup 성공" << std::endl;

	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ListenSocket == INVALID_SOCKET)
	{
		std::cerr << "소켓 생성 실패 : " << WSAGetLastError() << std::endl;
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
		std::cerr << "바인딩 실패: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR)
	{
		std::cerr << "리슨 실패: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	std::cout << "클라이언트 연결 대기 중..." << std::endl;

	SOCKET ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET)
	{
		std::cerr << "연결 수락 실패: " << WSAGetLastError() << std::endl;
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	std::cout << "클라이언트 연결 수락됨" << std::endl;


	char recvbuf[512];
	int recvbuflen = 512;

	while (true)
	{
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0)
		{
			std::cout << "클라이언트로부터 데이터 수신: " << std::string(recvbuf, iResult) << std::endl;

			std::string sendbuf;
			std::cout << "서버: ";
			std::getline(std::cin, sendbuf);

			iResult = send(ClientSocket, sendbuf.c_str(), (int)sendbuf.length(), 0);
			if (iResult == SOCKET_ERROR)
			{
				std::cerr << "데이터 송신 실패: " << WSAGetLastError() << std::endl;
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
		}
		else if (iResult == 0)
		{
			std::cout << "연결이 종료되었습니다." << std::endl;
			break;
		}
		else
		{
			std::cerr << "데이터 수신 실패: " << WSAGetLastError() << std::endl;
			break;
		}
	}

	
	closesocket(ClientSocket);
	//소켓 릴리즈
	closesocket(ListenSocket);
	WSACleanup();
	return 0;
}