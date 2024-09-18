#include <iostream>
using namespace std;

bool winrow(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		bool res = true;
		char same = board[i][0];
		if (same == '-')
		{
			continue;
		}
		for (int j = 1; j < 3; j++)
		{
			if (board[i][j] != same)
			{
				res = false;
				break;
			}
		}
		if (res == true)
		{
			return res;
		}
	}
	return false;
}

bool wincol(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		bool res = true;
		char same = board[0][i];
		if (same == '-')
		{
			continue;
		}
		for (int j = 1; j < 3; j++)
		{
			if (board[j][i] != same)
			{
				res = false;
				break;
			}
		}
		if (res == true)
		{
			return res;
		}
	}
	return false;
}

bool windiag1(char board[3][3])
{
	char same = board[0][0];
	if (same == '-')
	{
		return false;
	}
	for (int i = 1; i < 3; i++)
	{
		if (board[i][i] != same)
		{
			return false;
		}
	}
	return true;
}

bool windiag2(char board[3][3])
{

	char same = board[0][2];
	if (same == '-')
	{
		return false;
	}
	for (int i = 1; i < 3; i++)
	{
		if (board[i][2 - i] != same)
		{
			return false;
		}
	}
	return true;
}

void display(char board[3][3])
{

	cout << "\n";
	cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "---------\n";
	cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "---------\n";
	cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool completelyFilled(char board[3][3])
{
	bool res = true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '-')
			{
				res = false;
				return res;
			}
		}
	}
	return res;
}

void change(char board[3][3], int row, int col, int turn)
{

	if (turn == 0)
	{
		board[row][col] = 'O';
	}
	else
	{
		board[row][col] = 'X';
	}
}

bool filled(char board[3][3], int row, int col)
{

	return (board[row][col] == 'X' || board[row][col] == 'O');
}

int main()
{
begin:
	char board[3][3];
	fill_n(board[0], 3, '-');
	fill_n(board[1], 3, '-');
	fill_n(board[2], 3, '-');
	int turn = 1;
	string temp_turn = "a";

	cout << "First Player will play with \'X\' \n";
	cout << "Second Player will play with \'O\' \n";
	cout << "\n";
	while (true)
	{
		cout << "Which Player will turn first (1 or 2): ";
		getline(cin, temp_turn);

		if (temp_turn == "1")
		{
			turn = 1; // 0 represents Player-1 who plays with X
			break;
		}
		else if (temp_turn == "2")
		{
			turn = 0; // 0 represents Player-2 who plays with O
			break;
		}
		else
		{
			cout << "Wrong Input! Try Again\n\n";
		}
	}

	int row, col;
	while (true)
	{
		while (true)
		{
			cout << "\nEnter a row number (1 or 2 or 3): ";
			cin >> row;
			cout << "Enter a column number (1 or 2 or 3): ";
			cin >> col;
			if (row <= 0 || row >= 4)
			{
				cout << "Invalid Row Number Input! Try Again\n";
			}
			else if (col <= 0 || col >= 4)
			{
				cout << "Invalid Column Number Input! Try Again\n";
			}
			else if (filled(board, row - 1, col - 1))
			{
				cout << "Place Already Filled! Try Again\n";
			}
			else
			{
				break;
			}
		}
		change(board, row - 1, col - 1, turn);
		display(board);
		if (wincol(board) || winrow(board) || windiag1(board) || windiag2(board))
		{
			cout << (turn == 0 ? "Player-2 won the game!\n" : "Player-1 won the game!\n");
			break;
		}
		if (completelyFilled(board))
		{
			cout << "\n****It's a tie!!****\n";
			cout << "Board has been completely filled\n";
			break;
		}
		turn = (turn + 1) % 2;
	}
	string choice;
	cout << "\n\nDo you want to play again? (y/n) ";
	cout << "\nPress any other key to exit: ";
	getline(cin, choice);
	getline(cin, choice);
	if (choice == "y")
	{
		cout << endl;
		goto begin;
	}
}
