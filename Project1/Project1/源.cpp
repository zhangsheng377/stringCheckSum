#include <iostream>
//#include <iomanip>
//#include <bitset>

using namespace std;

char calculateCheckSum(char data[]);

int main() {

	cout << sizeof(unsigned char) << endl;
	char a[1024] = "ÕÅÊ¤¶«";
	//cin >> a;
	cout << a << endl;
	//cout << setiosflags(ios_base::hex) << a[0] << endl;
	printf("%c  0x%x  ASC:%d\n", a[0], a[0], a[0]);
	printf("%c  0x%x  ASC:%d\n", a[1], a[1], a[1]);
	printf("%c  0x%x  ASC:%d\n", a[2], a[2], a[2]);
	printf("%c  0x%x  ASC:%d\n", a[3], a[3], a[3]);
	cout << endl;
	/*
	unsigned char t;
	t = calculateCheckSum(a);
	printf("%c  0x%x  ASC:%d\n", (unsigned char)t);
	unsigned char tt;tt = 0x42;
	printf("%c  0x%x  ASC:%d\n", (unsigned char)0x42);
	printf("%c  0x%x  ASC:%d\n", (unsigned char)calculateCheckSum(a));
	*/
	char ttt[2];ttt[0] = calculateCheckSum(a);ttt[1] = '\0';
	printf("%c  0x%x  ASC:%d\n", ttt[0], ttt[0], ttt[0]);
	cout << endl;

	//cout << strlen(a) << endl;
	short l = strlen(a);
	a[l] = ttt[0];a[l + 1] = '\0';
	//cout << strlen(a) << endl;
	char tttt[1];tttt[0] = calculateCheckSum(a);
	printf("%c  0x%x  ASC:%d\n", tttt[0], tttt[0], tttt[0]);

	cin.get();cin.get();
	return 0;
}

char calculateCheckSum(char data[]) {
	unsigned char checkSum;
	short i;
	for (i = 0, checkSum = (unsigned char)0x00;i < (short)strlen(data);i++) {
		//printf("\n0x%x  +  0x%x\n", (unsigned char)checkSum, (unsigned char)data[i]);
		checkSum += (unsigned char)data[i];
		//checkSum &= 0xff;
		//printf("0x%x  \n\n", (unsigned char)checkSum);
	}
	//unsigned char t[1];t[0] = checkSum;
	//return checkSum;
	return ~checkSum;
}