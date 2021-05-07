#define DEFAULT_BUFLEN 4096
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#pragma comment(lib, "Ws2_32.lib")

int cipher(int character, int key) {
	if (character >= 'A' && character <= 'Z') {
		character += key;
		if (character > 'Z')
			character = character - 'Z' + 'A' - 1;
	}else if (character >= 'a' && character <= 'z') {
		character += key;
		if (character > 'z')
			character = character - 'z' + 'a' - 1;
	}

	return (char)character;
}

void GoTo(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int primeNum(int x) {
	for (int i = 2; i < x; i++)
		if (x % i == 0) 
			return 0;
	return 1;
}

int main() {
	int True = 1;
	int False = 0;

	FILE* chatLog = fopen("chatLog.txt", "w");
	char* p;
	char id[] = "104578";
	int recvBufLen = DEFAULT_BUFLEN, msgNum = 0, remainder = 0;
	char recvBuf[DEFAULT_BUFLEN], sendBuf[100], str[10];

	for (int i = 0; i < strlen(id) - 1; i++) {
		remainder += id[i] - '0';
	}
	remainder = remainder % (id[4] - '0');

	sprintf(str, "%d", remainder);

	/***************************************************************************************************/

	SetConsoleOutputCP(CP_UTF8);
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	WSADATA wsaData;	//winsock.h library, struktura obsahujuca data o socketovej implementacii

	int lines = 5;
	int iResult = 0;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);		//inicializacia, MAKEWORD - requestuje verziu 2.2 winsocku a nastavuje ju ako najvysiu verziu aka sa moze pouzit
	if (iResult != 0) {
		printf("WSAStartup failed : %d\n", iResult);
		return False;
	}

	struct addrinfo* result = NULL, * ptr = NULL;		//struktura ktora reprezentuje adresy a hostov pocas networkingu
	struct addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));			//makro vyplni istu cast pamate nulami
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	iResult = getaddrinfo("147.175.115.34", "777", &hints, &result);	//konvertovanie textu pisaneho ludom zrozumitelne do dynamicky alokovaneho linked listu

	if (iResult != 0) {
		printf("getaddrinfo failed : %d\n", iResult);
		WSACleanup();
		return False;
	}
	else printf("getaddrinfo didnt fail..\n");

	SOCKET ConnectSocket = INVALID_SOCKET;		//vytvaranie socketu
	ptr = result;
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);		//tahame info z getaddrinfo

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Error at socket() : %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return False;
	}
	else printf("Error at socket DIDNT occur..\n");
	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

	if (iResult == SOCKET_ERROR) printf("Not connected to server..\n");
	else printf("Connected to server!\n");

	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		WSACleanup();
		return False;
	}

	Sleep(250);

	/***************************************************************************************************/

	while (True) {
		GoTo(0, lines);
		switch (msgNum) {
			case 0:
				printf("Type here to start conversation: ");
				scanf("%s", sendBuf);
				break;
			case 1:
				strcpy(sendBuf, id);
				break;
			case 2:
				strcpy(sendBuf, "okay");
				break;
			case 3:
				strcpy(sendBuf, "7545477");
				break;
			case 4:
				strcpy(sendBuf, "753421");
				break;
			case 5:
				strcpy(sendBuf, str);
				break;
			case 6:
				strcpy(sendBuf, "333222111");
				break;
			case 7:
				strcpy(sendBuf, "123");
				break;
			case 8:
				strcpy(sendBuf, "okay");
				break;
			case 9:
				strcpy(sendBuf, "48");
				break;
			case 10:
				strcpy(sendBuf, "2");
				break;
			case 11:
				strcpy(sendBuf, "E.T.");
				break;
			case 12:
				strcpy(sendBuf, "PRIMENUMBER");
				break;
			case 13:
				strcpy(sendBuf, str);
				break;
			case 14:
				strcpy(sendBuf, "Trinity");
				break;
			case 15:
				strcpy(sendBuf, "polyadicke");
				break;
			case 16:
				strcpy(sendBuf, "half-duplex");
				break;
			case 17:
				strcpy(str, "OBVMHKR");
				strcpy(sendBuf, "");
				for (int i = 0; i < strlen(str); i++) {
					sendBuf[i] = cipher(str[i], 7);
					sendBuf[i + 1] = '\0';
				}
				break;
			default:
				printf("Connection closed!\n");
				break;
		}
		if (msgNum > 17)
			break;

		printf("Sending: %s\n", sendBuf);

		iResult = send(ConnectSocket, sendBuf, strlen(sendBuf), 0);

		if (iResult == SOCKET_ERROR) {
			printf("send failed: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return False;
		}
	
		iResult = recv(ConnectSocket, recvBuf, recvBufLen, 0);

		if (msgNum == 7) {
			int i;
			for (i = 0; i < 132; i++)
				recvBuf[i] = recvBuf[i] ^ 55;
			recvBuf[i] = '\0';
		}else if (msgNum == 12) {
			int index = 0;
			for (int i = 1; i < iResult; i++) {
				if (primeNum(i + 1)) {
					str[index] = recvBuf[i];
					index++;
				}
			}
		}else {
			p = strchr(recvBuf, '\n');
			recvBuf[p - recvBuf + 1] = '\0';
		}

		lines += 3;
		int x = 0;

		while (iResult > x) {
			GoTo(60, lines);
			for (int i = 0; i < 60; i++) {
				if (recvBuf[x] == ' ' && i > 50) {
					printf("\n");
					x++;
					break;
				}
				else if (iResult < x) break;
				else {
					printf("%c", recvBuf[x]);
					x++;
				}
			}
			lines++;
		}
		msgNum++;

		fprintf(chatLog, "Oliver : %s\n", sendBuf);
		fprintf(chatLog, "Morpheus : %s\n", recvBuf);
	}
	fclose(chatLog);
	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}