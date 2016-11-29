#include<iostream>
#include<stdio.h>
#include<fstream>	
#include<vector>
#include <stdbool.h>
#include <stack>


//Tested vector buffer

using namespace std;

struct cell {
	vector<char> buff;
	int xcoord;
	int ycoord;
	int zcoord;
	bool visited;
	bool end;
};

/*
void checkNeighbors(cell currentPos[i][j][k]){

if(maze[i][j][k].buff[0] == '1'){
cout << "N ";
currentPos = maze[i][j-1][k];
}
if(maze[i][j][k].buff[1] == '1'){
cout << "E ";
currentPos = maze[i][j][k+1];
}
if(maze[i][j][k].buff[2] == '1'){
cout << "S ";
currentPos = maze[i][j+1][k];
}
if(maze[i][j][k].buff[3] == '1'){
cout << "W ";
currentPos = maze[i][j][k-1];
}
if(maze[i][j][k].buff[4] == '1'){
cout << "U ";
currentPos = maze[i+1][j][k];
}
if(maze[i][j][k].buff[5] == '1'){
cout << "D ";
currentPos = maze[i-1][j][k];
}

}
*/

void printCell(cell cells) {
	cout << cells.xcoord << "," << cells.ycoord << "," << cells.zcoord;
}

int main() {

	ifstream fin;
	fin.open("Text.txt", ios::in);

	char mychar;
	//vector<char> buffer;     
	int problems;
	int levels, rows, columns;
	int startx;  //starting cell x coord
	int starty;  //starting cell y coord
	int startz;  //starting cell z coord
	int endx;  //ending cell x coord
	int endy;  //ending cell y coord
	int endz;  //ending cell z coord
	vector< vector < vector<cell > > >maze;   //create maze



											  //take input from text file
	fin >> problems;
	fin >> levels;
	fin >> rows;
	fin >> columns;

	fin >> startx;
	fin >> starty;
	fin >> startz;

	fin >> endx;
	fin >> endy;
	fin >> endz;


	//***************************************************************************************DELETE WHEN DONE
	cout << "Probs :" << problems << endl;                                                //prints our # of problems
	cout << "Levels : " << levels << " Rows: " << rows << " Colums: " << columns << endl; //prints our levels, rows, and columns

	cout << "Start: (" << startx << "," << starty << "," << startz << ")\n";             //print out start coord
	cout << "End: (" << endx << "," << endy << "," << endz << ")\n";                     //print out end coord
																						 //***************************************************************************************



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
				cout << "(" << maze[i][j][k].xcoord << "," << maze[i][j][k].ycoord << "," << maze[i][j][k].zcoord << ")";
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


	//assign start and end cells in the maze
	maze[startx][starty][startz].visited = true;
	maze[endx][endy][endz].end = true;


	cell currentPos;              //keep track of current cell
	currentPos = maze[startx][starty][startz];

	stack<char> mazeDirections;
	//checkNeighbors(currentPos);

	//char x = '1';

	/*
	switch (maze[i][j][k].buff[i]) {
	case maze[i][j][k].buff[i]:
	cout << "N ";
	break;
	case '1':
	cout << "E ";
	break;
	case '2':
	cout << "S";
	break;
	case '3':
	cout << "W ";
	break;
	case '4':
	cout << "U ";
	break;
	case '5':
	cout << "D ";
	break;
	default:
	cout << "value of x unknown";
	}
	*/
	cout << endl;

	for (int i = 0; i < 6; i++) {                                      //delete when done, used to see if directions were working
		cout << maze[0][0][1].buff[i];
	}

	cout << endl;
	cout << "Print cell : ";
	printCell(currentPos);

	//currentPos.xcoord = 3;
	cout << endl;
	cout << "Print cell : ";
	printCell(currentPos);


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			for (int k = 0; k < levels; k++) {

				if (currentPos.buff[0] == '1') {
					cout << "N ";
					currentPos = maze[i][j - 1][k];
					continue;
				}
				else if (currentPos.buff[1] == '1') {
					cout << "E ";
					currentPos = maze[i][j][k + 1];
					continue;
				}
				else if (currentPos.buff[2] == '1') {
					cout << "S ";
					currentPos = maze[i][j + 1][k];
					continue;
				}
				else if (currentPos.buff[3] == '1') {
					cout << "W ";
					currentPos = maze[i][j][k - 1];
					continue;
				}
				else if (currentPos.buff[4] == '1') {
					cout << "U ";
					currentPos = maze[i + 1][j][k];
					continue;
				}
				else if (currentPos.buff[5] == '1') {
					cout << "D ";
					currentPos = maze[i - 1][j][k];
					continue;
				}

			}
		}
	}

}
