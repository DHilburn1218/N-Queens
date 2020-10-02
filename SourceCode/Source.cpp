// Driver program for the ChessBoard class
// which solves the N-Queens problem for
// board sizes of 4 to 12.

#include <iostream>
#include<chrono>
#include<thread>
#include "ChessBoard.h"

int main()
{
	std::chrono::milliseconds waitTime(2500);

	std::cout << "This program demonstrates the N-Queen Problems; being able to set" << std::endl <<
		"a Queen on every row and column of a chessboard so that they cannot" << std::endl <<
		"attack each other." << std::endl <<
		"This program uses Recursion and Backtracking in order to find the solutions." << 
		std::endl << std::endl << std::endl;
	std::this_thread::sleep_for(waitTime);

	// Create a board
	ChessBoard myBoard;

	/* Loop through board sizes from 3 to 13.
	   Since 3 and 13 are invalid you should see
	   board sizes 4 and 12 twice. */
	for (int i = 3; i <= 13; i++)
	{
		myBoard.setSize(i);

		/* Attempt to solve the N-Queens Problem. If the solve
		   code is working it should find solutions for all
		   sizes. */
		if (!myBoard.solve())
			std::cout << "Sorry, no solution was found for board size "
			<< myBoard.getSize() << "." << std::endl << std::endl;
		else
		{
			std::cout << "Size " << myBoard.getSize()
				<< " solution:" << std::endl;
			myBoard.displayBoard();
			std::cout << std::endl << std::endl;
		}
		std::this_thread::sleep_for(waitTime);
	}
	
	std::cout << "Press Any Key to Exit";
	std::cin.ignore();
	return 0;
}