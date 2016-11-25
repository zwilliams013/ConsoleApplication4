#include<iostream>
#include<stdio.h>
#include<fstream>	
#include<vector>

//

using namespace std;


//north, east, south, west, up, down

/*void printVec(vector<char> vect) {
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
}*/

int main() {

	//std::cout << "Hello World \n";4

	ifstream fin;
	fin.open("Text.txt", ios::in);

	char mychar;
	vector<char> buffer;


	//printVec(buffer);
	for (int i = 0; i < buffer.size(); i++) {
		cout << buffer[i] << " ";
	}
	cout << endl;

	while ( !fin.eof()) {
		fin.get(mychar);
		if (mychar == ' ' || mychar == '\n') {
			break;
		}
		//cout << mychar;
		buffer.push_back(mychar);
	}


	cout << endl;
	cout << "Buffer size is: " << buffer.size() << endl;
	for (int i = 0; i < buffer.size(); i++) {
		cout << buffer[i] << " ";
	}
	cout << "\n";

}