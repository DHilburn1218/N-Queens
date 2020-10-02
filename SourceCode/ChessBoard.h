/**
@author Darrick Hilburn

Written for CS 250

ChessBoard.h
*/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard
{
private:
	char** boardPtr;	// Double Pointer to chessboard 
	int boardSize;		// Square size of the board; size of 4 = 4x4

	/**
	placeQueens is a helper function that is called recursively to place
	queens on the board.
	
	@param row: row in boardPtr we are currently examining.
	@param col: column in boardPtr we are currently examining.

	@return: True if all queens could be placed; false otherwise
	*/
	bool placeQueens(int row, int col);

	/**
	makeBoard dynamically allocates the boardPtr data on the heap.
	*/
	void makeBoard();

	/**
	buildBoard is a helper function that is called to 
	fill the boardPtr with all asterisks.
	*/
	void buildBoard();

	/**
	clearBoard removew the boardPtr from the heap.
	*/
	void clearBoard();

	/**
	fixSize corrects the size of the board if it needs to.

	@return: Bool indicating that the board had to be resized.
			  Returns true if resize had to happen; false otherwise.
	*/
	bool fixSize();

	/**
	underAttack checks behind the piece we are currently examining to see
	if it is under attack by another queen.

	@param row: row in boardPtr we are currently examining.
	@param col: column in boardPtr we are currently examining.
	@return: returns True if the piece at this position would be
			 under attack by another piece; false otherwise.
	*/
	bool underAttack(int row, int col);

	/**
	setQueen allocates the character 'Q' to the observed space
	in the boardPtr.

	@param row: row in boardPtr we are currently examining.
	@param col: column in boardPtr we are currently examining.
	*/
	void setQueen(int row, int col);

	/**
	removeQueen allocates the character '*' to the observed space
	in the boardPtr.

	@param row: row in boardPtr we are currently examining.
	@param col: column in boardPtr we are currently examining.
	*/
	void removeQueen(int row, int col);

	/**
	findAndRemoveQueen checks a column to see if there
	is a queen in it.

	@param col: Column we are observing.
	*/
	int findAndRemoveQueen(int col);
	
public:
	ChessBoard();
	ChessBoard(int size);
	virtual ~ChessBoard();

	/**
	setSize sets the size of the boardPtr

	@param newSize: size to change boardSize to
	*/
	void setSize(int newSize);

	/**
	getSize returns the current size of the board.
	
	@return: returns boardSize
	*/
	int getSize();

	/**
	solve calls placeQueens starting at position 0,0

	@return: Returns the passed return value of placeQueens(0, 0)
	*/
	bool solve();

	/**
	displayBoard shows the placement of the queens on the boardPtr.

	Empty space is represented by '*'; queens are represented by 'Q'
	*/
	void displayBoard();
};

#endif