#include<iostream>
#include<stdio.h>
#include<fstream>	
#include<vector>

//Tested vector buffer

using namespace std;

struct cell {
	vector<char> buff;
	int xcoord;
	int ycoord;
	int zcoord;

	//buff.resize(6);
};

int main() {

	ifstream fin;
	fin.open("Text.txt", ios::in);

	char mychar;
	//vector<char> buffer;     
	int problems;
	int levels, rows, columns;
	
	
	//take input from text file
	fin >> problems;
	fin >> levels;
	fin >> rows;
	fin >> columns;
	

	cout << "Probs :" << problems << endl;
	cout << "Levels : " << levels << " Rows: " << rows << " Colums: " << columns << endl;


	//create maze
	vector< vector < vector<cell > > >maze;


	//Resize maze
	maze.resize(rows);
	for (int i = 0; i < rows; i++) {
		maze[i].resize(columns);
		for (int j = 0; j < columns; j++) {
			maze[i][j].resize(levels);
		}
	}




	//Set up coordinates
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			for (int k = 0; k < levels; k++) {
				maze[i][j][k].xcoord = i;
				maze[i][j][k].ycoord = j;
				maze[i][j][k].zcoord = k;
			}
		}
	}

	//print out coordinates
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			for (int k = 0; k < levels; k++) {
				cout << "(" << maze[i][j][k].xcoord << "," << maze[i][j][k].ycoord  << "," << maze[i][j][k].zcoord << ")";
			} cout << endl;
		}
	}


	//Insert text file into cell buffers
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			for (int k = 0; k < levels; k++) {
				for (int z = 0; z < 6; z++) {
					fin >> mychar;
					maze[i][j][k].buff.push_back(mychar);
					//cout << maze[i][j][k].buff[z];
				}
			}
		}
	}


	//Print out buffers of all the cells     ******DELETE WHEN DONE******
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			for (int k = 0; k < levels; k++) {
				for (int z = 0; z < 6; z++) {
					//cout << maze[i][j][k].buff.push_back(mychar);
				
					cout << maze[i][j][k].buff[z];
					
				} cout << endl;
			}
		}
	}

	//for (int i = 0; i < maze.size(); i++) {
	/*	if (mychar == ' ') {
			//continue;
			fin.get(spaces);
		}*/
	/*

		for (int j = 0; j < 6; j++) {
				//while (!fin.eof()) {
				fin >> mychar;
		//		if (mychar == ' ' || mychar == '\n') {
			//		//continue;
			//	}
				
				maze[i][j][z].buff.push_back(mychar);
				//}
			}

		}
	*/
/*
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < columns; j++) {
			for (int j = 0; j < 6; j++) {

				cout << maze[i][j].buff[j];
			}cout << " ";
		}
	}
	*/



	//cout << "\n" << maze[1].buff[0];

	//cout << maze[3].buff[5];
	
	cout << endl;


	/*for (int i = 0; i < 20; i++) {
		cout << "\n Character in maze: " << maze[0].buff[i] << endl;
	}

	/*
	for (int i = 0; i < buffer.size(); i++) {
		cout << buffer[i] << " ";
	}
	cout << endl;
	*/



	/*
	//printVec(buffer);
	for (int i = 0; i < buffer.size(); i++) {
		cout << buffer[i] << " ";
	}
	cout << endl;

	*/
	/*



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
	*/
}
