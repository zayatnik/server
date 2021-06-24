#include "sockandaddr.h"

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996) 

using namespace std;

int main() {
	WSADATA wsaData;
	WSAStartup(MAKEWORD(1, 1), &wsaData);
	sockandaddr s(getport());
	char* buf = new char(getN());
	sockaddr_in ad = s.retad();
	bindandcout(s.retsock(), s.retad());
	bool fl = 0;
	int len = sizeof(s.retad());
	fstream inOut;
	char* name = nameforfile();
	int soff = 0;
	while (fl == 0) {
		int n = recvfrom(s.retsock(), buf, getN(), 0, (sockaddr*)&ad, &len);
		if (soff > 104857600) {
			name = nameforfile();
			soff = 0;
		}
		inOut.open(name, ios::app | ios::binary);
		writedata(buf, n, inOut);
		soff = soff + n;
		inOut.close();
	}
	return 0;
}