#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

int main()
{
    WSADATA wsaData;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        std::cerr << "WSAStartup ����: " << iResult << std::endl;
        return 1;
    }

    std::cout << "WSAStartup ����" << std::endl;

    SOCKET ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET)
    {
        std::cerr << "���� ���� ����: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_port = htons(27015); // ������ ������ ��Ʈ ��ȣ

    // inet_pton�� ����Ͽ� IP �ּҸ� ����
    iResult = inet_pton(AF_INET, "127.0.0.1", &clientService.sin_addr);
    if (iResult <= 0)
    {
        if (iResult == 0)
            std::cerr << "��ȿ���� ���� �ּ� �����Դϴ�." << std::endl;
        else
            std::cerr << "inet_pton ����: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    iResult = connect(ConnectSocket, (SOCKADDR*)&clientService, sizeof(clientService));
    if (iResult == SOCKET_ERROR)
    {
        std::cerr << "���� ����: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "������ ���� ����" << std::endl;

    char recvbuf[512];
    int recvbuflen = 512;

    while (true)
    {
        std::string sendbuf;
        std::cout << "Ŭ���̾�Ʈ: ";
        std::getline(std::cin, sendbuf);

        iResult = send(ConnectSocket, sendbuf.c_str(), (int)sendbuf.length(), 0);
        if (iResult == SOCKET_ERROR)
        {
            std::cerr << "������ �۽� ����: " << WSAGetLastError() << std::endl;
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0)
        {
            std::cout << "�����κ��� ������ ����: " << std::string(recvbuf, iResult) << std::endl;
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

    // ���� �ݱ�
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}