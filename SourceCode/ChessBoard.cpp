/**
@author Darrick Hilburn

Written for CS 250

ChessBoard.cpp
*/

#include "ChessBoard.h"
#include <iostream>
using std::cout;
using std::endl;

ChessBoard::ChessBoard() : boardSize(8)
{
	makeBoard();
	buildBoard();
}

ChessBoard::ChessBoard(int size) : boardSize(size)
{
	fixSize();
	makeBoard();
	buildBoard();
}

ChessBoard::~ChessBoard()
{
	clearBoard();
}

/** REQUIRED HELPER METHODS**/
bool ChessBoard::placeQueens(int row, int col)
{
	if (col >= boardSize)
		return true;
	else
	{
		while (row < boardSize && underAttack(row, col))
			row++;
		if (row < boardSize)
		{
			setQueen(row, col);
			if (!placeQueens(0, ++col))
			{
				int rmvPos = findAndRemoveQueen(--col);
				row = ++rmvPos;
			}
			else
				return true;
		}
		else
		{
			return false;
		}
		placeQueens(row, col);
	}
}

/** ADDED HELPER METHODS**/
void ChessBoard::makeBoard()
{
	boardPtr = new char*[boardSize];
	for (int i = 0; i < boardSize; i++)
		boardPtr[i] = new char[boardSize];
}

void ChessBoard::buildBoard()
{
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			boardPtr[i][j] = '*';
}

void ChessBoard::clearBoard()
{
	for (int i = 0; i < boardSize; i++)
		delete[] boardPtr[i];
	delete[] boardPtr;
}

bool ChessBoard::fixSize()
{
	bool fixed = false;
	if (boardSize < 4)
	{
		std::cout << "Size " << boardSize << " is too small; setting to minimum size: 4" << std::endl;
		boardSize = 4;
		fixed = true;
	}
	else if (boardSize > 12)
	{
		std::cout << "Size " << boardSize << " is too big; setting to maximum size: 12" << std::endl;
		boardSize = 12;
		fixed = true;
	}
	return fixed;
}

void ChessBoard::setQueen(int row, int col)
{
	boardPtr[row][col] = 'Q';
}

void ChessBoard::removeQueen(int row, int col)
{
	boardPtr[row][col] = '*';
}

int ChessBoard::findAndRemoveQueen(int col)
{
	int oldPos = -1;
	int row = 0;
	while (row < boardSize && boardPtr[row][col] != 'Q')
		row++;
	if (row < boardSize)
	{
		removeQueen(row, col);
		oldPos = row;
	}
	return oldPos;
}

bool ChessBoard::underAttack(int row, int col)
{
	bool attacked = false;
	int i = col; int j = 1;
	/**
	This while loop checks the horizontal and diagonals behind the
	currently observed square.
	As this builds from left to right, we are not concerned with what
	is in front of the observed square, which will be empty space.
	*/
	while (i >= 0 && !attacked)
	{
		if (boardPtr[row][--i] == 'Q') attacked = true;
		if ((row + j < boardSize) && boardPtr[row + j][i] == 'Q') attacked = true;
		if ((row - j >= 0) && boardPtr[row - j][i] == 'Q') attacked = true;
		++j;
	}
	return attacked;
}

/** PUBLIC METHODS**/
void ChessBoard::setSize(int newSize)
{
	//clearBoard();
	boardSize = newSize;
	fixSize();
	makeBoard();
	buildBoard();
}

int ChessBoard::getSize()
{
	return boardSize;
}

bool ChessBoard::solve()
{
	placeQueens(0, 0);
	return true;
}

void ChessBoard::displayBoard()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
			cout << boardPtr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}