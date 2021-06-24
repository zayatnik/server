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

#pragma once
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996) 

using namespace std;

//���������� ������ ����� �� �������� �����
int getport() {
	string port;
	ifstream inf;
	inf.open("infile.txt");
	getline(inf, port, '\n');
	inf.close();
	int PORT = atoi(port.c_str());
	return PORT;
}

//���������� ������������ ����� ��������� ���������
int getN() {
	string n;
	ifstream inf;
	inf.open("infile.txt");
	getline(inf, n, '\n');
	getline(inf, n, '\n');
	inf.close();
	int N = atoi(n.c_str());
	return N;
}

//���������� � ����� �������� � ��� ����������
void bindandcout(SOCKET s, struct sockaddr_in ad) {
	if (bind(s, (LPSOCKADDR)&ad, sizeof(ad)) == SOCKET_ERROR)
		cout << "connetcion error\n";
	else
		cout << "connection is successful\n";
}

//���������� ��������� �������� ������
sockaddr_in fill(int PORT) {
	sockaddr_in ad;
	ad.sin_family = AF_INET;
	ad.sin_port = htons(PORT);
	ad.sin_addr.s_addr = INADDR_ANY;
	return ad;
}

//����� ������
void printerror() {
	cout << "ERROR";
	system("pause");
}

//������� ��� ������ ���� ��������� �� ���� � ������
char* colontodash(char* a) {
	for (int i = 0; i < strlen(a); i++)
		if (a[i] == ':')
			a[i] = '-';
	return a;
}

//�������� ����� �������� �����
char* nameforfile() {
	time_t rawtime;
	time(&rawtime);
	char* a = ctime(&rawtime);
	a = colontodash(a);
	a[strlen(a) - 1] = '.';
	strcat(a, "antz");
	return a;
}

//����� ����� ��������� � ����
void longout(int n, fstream& inOut) {
	int n1 = n;
	inOut << (unsigned char(n1 >> 8));
	n1 = n1 - (n1 >> 8);
	inOut << (unsigned char(n1));
}

//����� ��������� � ����
void mesout(int n, fstream& inOut, char buf[]) {
	for (int i = 0; i < n; i++)
		inOut << unsigned char(int(buf[i]));
}

//����� ������ �������� ������
void writedata(char buf[], int n, fstream& inOut) {
	if (n == -1)
		printerror();
	longout(n, inOut);
	mesout(n, inOut, buf);
	cout << '\n' << n << " bytes";
}