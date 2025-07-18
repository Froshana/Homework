#include <iostream>
using namespace std;

// Завдання 1 //

const int mapHEIGHT = 3;
const int mapWDTH = 3;

char mapBoard [mapHEIGHT][mapWDTH]= {
	{' ',' ',' '},
	{' ',' ',' '},
	{' ',' ',' '}
};

void printBoard(){
	for(int i = 0; i < mapHEIGHT; i++){
		cout << " ";
		for (int j = 0; j < mapWDTH; j++){
			cout << mapBoard[i][j];
			if (j < mapWDTH - 1)
			cout << " | ";
		}
		cout << endl;
		if (i < mapWDTH - 1)
		cout << "---+---+--- " << endl;
	}
}

void playerMove(char symbol){
	int row, col;
	while (true){
		cout << "Гравець " << symbol << ", ведіть рядок (1-3) та стовпець (1-3) : ";
		cin >> row >> col;
		row--;
		col--;

		if (row >= 0 && row < mapHEIGHT &&
			col >= 0 && col < mapWDTH &&
			mapBoard[row][col] == ' '){

				mapBoard [row][col] = symbol;
				break;
			} else{
				cout << "Будь ласка, введіть ще раз! ";
		}
	}
	
}

 int main (){
	printBoard();

	playerMove('X');
	printBoard();

	playerMove('O');
	printBoard();

	playerMove('X');
	printBoard();

	playerMove('X');
	printBoard();

	playerMove('X');
	printBoard();


	return 0;
 }
// Я просто по фану вирішила написати гру

 // Завдання 2 //

#include <iostream>
using namespace std;

int main() {
 const int HEIGHT = 3;
 const int WDTH = 3;

 	int board [HEIGHT][WDTH];

	for	(int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WDTH; j++){
		board[i][j] = 0;
		}
	}

	for(int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WDTH; j++){
		cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

// Завдання 3 //

	unsigned short SomeArray[5][4];
	for (int i = 0; i < 4; i++) // тут переплутані стовпці та рядки, спочатку рядки (5) потім стовпці (4), тут один рядок залишається неініціалізованим
    		for (int j = 0; j < 5; j++) // це вихід за межі стовпця, тут повинно бути цифра 4, або можна поміняти місцями цифри
        			SomeArray[i][j] = i + j; //



// Завдання 4 //

	unsigned short SomeArray[5][4];
	for (int i = 0; i <= 5; i++) // == 5 це вихід на межі масиву, може бути <= 4, бо нумерація починається з 0
    		for (int j = 0; j <= 4; j++) // тут так само, може бути <=3
	        	SomeArray[i][j] = 0;
