#include<iostream>
#include<stdio.h>
#include<fstream>	
#include<vector>
#include <stdbool.h>
#include <deque>
#include <stack>


//Tested vector buffer

using namespace std;



struct cell {
	vector<char> buff;
	int xcoord, ycoord, zcoord;
	bool visited;
	bool end;
	cell *parent;
	cell *prev;

	vector<int> nbrs;
	

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
	cout << endl;
	cout << "(" << cells.xcoord << "," << cells.ycoord << "," << cells.zcoord << ")";
	cout << " ";
	for (int i = 0; i < 6; i++) {                                      //delete when done, used to see if directions were working
		cout << cells.buff[i];
	}cout << " ";
}

void printStack(stack<cell> S) {
	stack<cell> reverse;
	while (!S.empty()) {
		reverse.push(S.top());
		S.pop();
	}


	while (!reverse.empty()) {
		cell n = reverse.top();
		cout << "(" << n.xcoord << "," << n.ycoord << "," << n.ycoord << ") ";
		reverse.pop();
	}
}


int main() {

	ifstream fin;
	fin.open("Text.txt", ios::in);

	char mychar;
	//vector<char> buffer;     
	int problems;
	int levels, rows, columns;
	int startx, starty, startz;  //starting cell coord
	int endx, endy, endz;  //ending cell coord
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
	cout << "End: (" << endx << "," << endy << "," << endz << ")\n\n";                     //print out end coord
																						   //***************************************************************************************



																						   //Resize maze
	maze.resize(levels);
	for (int i = 0; i < levels; i++) {
		maze[i].resize(rows);
		for (int j = 0; j < rows; j++) {
			maze[i][j].resize(columns);
		}
	}

	//Set up coordinates
	for (int i = 0; i < levels; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < columns; k++) {
				maze[i][j][k].xcoord = i;
				maze[i][j][k].ycoord = j;
				maze[i][j][k].zcoord = k;
			}
		}
	}

	//print out coordinates
	for (int i = 0; i < levels; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < columns; k++) {
				cout << "(" << maze[i][j][k].xcoord << "," << maze[i][j][k].ycoord << "," << maze[i][j][k].zcoord << ")";
			} cout << endl;
		}cout << endl;
	}


	//Insert text file into cell buffers
	for (int i = 0; i < levels; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < columns; k++) {
				for (int z = 0; z < 6; z++) {
					fin >> mychar;
					maze[i][j][k].buff.push_back(mychar);
					maze[i][j][k].visited = false;
					maze[i][j][k].end = false;
					//cout << maze[i][j][k].buff[z];
				}
			}
		}
	}


	//Print out buffers of all the cells     ******DELETE WHEN DONE******
	for (int i = 0; i < levels; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < columns; k++) {
				for (int z = 0; z < 6; z++) {
					//cout << maze[i][j][k].buff.push_back(mychar);

					cout << maze[i][j][k].buff[z];

				}cout << " ";
			}cout << endl;
		}
	}


	//assign start and end cells in the maze
	maze[startx][starty][startz].visited = true;
	maze[endx][endy][endz].end = true;


	cell currentPos;              //keep track of current cell
	cell endPos;
	currentPos = maze[startx][starty][startz];
	endPos = maze[endx][endy][endz];

	deque<char> mazeDirections;              //create a deque to hold the directions
	cout << endl;

	/*  for(int i = 0; i < 6; i++){                                      //delete when done, used to see if directions were working
	cout << maze[1][0][0].buff[i];
	}
	*/
	cout << endl;



	int i = startx;
	int j = starty;
	int k = startz;
	int count = 0;
	printCell(maze[startx][starty][startz]);   //print the start cell

	stack<cell> mazeStack;
	mazeStack.push(currentPos);

	//mazeStack.push(currentPos);
	//mazeStack.push(endPos);
	//cout << "Printing stack ";
	//printStack(mazeStack);

	currentPos.prev = NULL;

	//DFS implementation
	while (!currentPos.end) {
		if (count == 15) {
			break;
		}
		if (currentPos.buff[0] == '1' && currentPos.visited!= true) {
			cout << "N ";
			mazeDirections.push_back('N');
			count++;
			j -= 1;
			currentPos.ycoord -=1;
			mazeStack.push(currentPos);
			currentPos.visited = true;
			printCell(currentPos);
			printStack(mazeStack);
			// continue;
		}
		else if (currentPos.buff[1] == '1' && maze[i][j][k + 1].visited != true) {
			cout << "E ";
			mazeDirections.push_back('E');
			count++;
			k += 1;
			currentPos.zcoord +=1;
			mazeStack.push(currentPos);
			currentPos.visited = true;
			printCell(currentPos);
			printStack(mazeStack);
			//  continue;
		}
		else if (currentPos.buff[2] == '1' && maze[i][j + 1][k].visited != true) {
			//   cout << "Count: " << count << endl;
			count++;
			cout << "S ";
			mazeDirections.push_back('S');
			j += 1;
			currentPos.ycoord +=1;
			mazeStack.push(currentPos);
			currentPos.visited = true;
			printCell(currentPos);
			printStack(mazeStack);
			// continue;
		}
		else if (currentPos.buff[3] == '1' && maze[i][j][k - 1].visited != true) {
			cout << "W ";
			count++;
			mazeDirections.push_back('W');
			k -= 1;
			currentPos.zcoord -= 1;
			mazeStack.push(currentPos);
			currentPos.visited = true;
			printCell(currentPos);
			printStack(mazeStack);
			// continue;
		}
		else if (currentPos.buff[4] == '1' && maze[i+1][j][k].visited != true) {
			//cout << "Count: " << count << endl;
			count++;
			cout << "U ";
			mazeDirections.push_back('U');
			i += 1;
			currentPos.xcoord += 1;
			mazeStack.push(currentPos);
			currentPos.visited = true;
			printCell(currentPos);
			printStack(mazeStack);
			//continue;
		}
		else if (currentPos.buff[5] == '1' && maze[i - 1][j][k].visited != true) {
			count++;
			cout << "D ";
			mazeDirections.push_back('D');
			i -= 1;
			currentPos.xcoord -= 1; 
			mazeStack.push(currentPos);
			currentPos.visited = true;
			printCell(currentPos);
			printStack(mazeStack);

			//continue;
		}
		//else {
		//	mazeStack.pop();
		//	mazeDirections.pop_front();
		//	currentPos = mazeStack.top();
		//}

		/*
		else if(maze[i][j][k].buff[0] == '1'){
		cout << "N ";
		count ++;
		mazeDirections.push_back('N');
		j-=1;
		currentPos = maze[i][j][k];
		maze[i][j][k].visited = true;
		printCell(currentPos);
		// continue;
		}
		else if(maze[i][j][k].buff[1] == '1'){
		cout << "E ";
		count ++;
		mazeDirections.push_back('E');
		k += 1;
		currentPos = maze[i][j][k];
		maze[i][j][k].visited = true;
		printCell(currentPos);
		//  continue;
		}
		else if(maze[i][j][k].buff[2] == '1'){
		//   cout << "Count: " << count << endl;
		count ++;
		cout << "S ";
		mazeDirections.push_back('S');
		j+=1;
		currentPos = maze[i][j][k];
		maze[i][j][k].visited = true;
		printCell(currentPos);
		// continue;
		}
		else if(maze[i][j][k].buff[3] == '1'){
		cout << "W ";
		mazeDirections.push_back('W');
		count ++;
		k-=1;
		currentPos = maze[i][j][k];
		maze[i][j][k].visited = true;
		printCell(currentPos);
		// continue;
		}
		else if(maze[i][j][k].buff[4] == '1'){
		//cout << "Count: " << count << endl;
		count ++;
		cout << "U ";
		mazeDirections.push_back('U');
		i += 1;
		currentPos = maze[i][j][k];
		currentPos.visited = true;
		printCell(currentPos);
		//continue;
		}
		else if(maze[i][j][k].buff[5] == '1'){
		count ++;
		cout << "D ";
		mazeDirections.push_back('D');
		i -= 1;
		currentPos = maze[i][j][k];
		maze[i][j][k].visited = true;
		printCell(currentPos);
		//continue;
		}
		}

		/*
		cout << "\n\n";
		maze[1][1][1].visited = true;
		cout << "Check " << maze[1][1][0].visited;
		cout << "\n\n";
		*/
	}
		///check visited functions makes a grid of 1s and 0s 
		cout << "\n\n";
		for (int i = 0; i < levels; i++) {
			for (int j = 0; j < rows; j++) {
				for (int k = 0; k < columns; k++) {
					cout << maze[i][j][k].visited << " ";
				} cout << endl;
			}cout << endl;
		}

		for (int i = 0; i < mazeDirections.size(); i++) { //prints out the maze direction deque, this will be used for the output file
			cout << mazeDirections[i] << " ";
		}



	}

