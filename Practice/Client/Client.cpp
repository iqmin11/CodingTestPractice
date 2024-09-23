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
        std::cerr << "WSAStartup 실패: " << iResult << std::endl;
        return 1;
    }

    std::cout << "WSAStartup 성공" << std::endl;

    SOCKET ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET)
    {
        std::cerr << "소켓 생성 실패: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_port = htons(27015); // 서버와 동일한 포트 번호

    // inet_pton을 사용하여 IP 주소를 설정
    iResult = inet_pton(AF_INET, "127.0.0.1", &clientService.sin_addr);
    if (iResult <= 0)
    {
        if (iResult == 0)
            std::cerr << "유효하지 않은 주소 형식입니다." << std::endl;
        else
            std::cerr << "inet_pton 실패: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    iResult = connect(ConnectSocket, (SOCKADDR*)&clientService, sizeof(clientService));
    if (iResult == SOCKET_ERROR)
    {
        std::cerr << "연결 실패: " << WSAGetLastError() << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "서버에 연결 성공" << std::endl;

    char recvbuf[512];
    int recvbuflen = 512;

    while (true)
    {
        std::string sendbuf;
        std::cout << "클라이언트: ";
        std::getline(std::cin, sendbuf);

        iResult = send(ConnectSocket, sendbuf.c_str(), (int)sendbuf.length(), 0);
        if (iResult == SOCKET_ERROR)
        {
            std::cerr << "데이터 송신 실패: " << WSAGetLastError() << std::endl;
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0)
        {
            std::cout << "서버로부터 데이터 수신: " << std::string(recvbuf, iResult) << std::endl;
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

    // 소켓 닫기
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}