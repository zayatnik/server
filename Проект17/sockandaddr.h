#include <WinSock2.h>
#include <iostream>
#include <Windows.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <istream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <ctime>
#include "commonfunctions.h"

#pragma once
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996) 

using namespace std;

//�����, ���������� ����� � ��� �����
class sockandaddr {
private:
	SOCKET s;
	sockaddr_in ad;
public:

	//�����������
	sockandaddr(int PORT) {
		s = socket(PF_INET, SOCK_DGRAM, 0);
		cout << "Port: " << PORT << "\n";
		ad = fill(PORT);
	}

	//�������, ������������ �����
	SOCKET retsock() {
		return s;
	}

	//�������, ������������ ����� ������
	sockaddr_in retad() {
		return ad;
	}
};