/* Connect Four */
#include "connect4.h"

int SecondPlacePrize(int prize1, int prize2, int prize3)
{
	/* Compares to see whether prize1 is the middle */
	if ((prize1 >= prize2) && (prize1 <= prize3) || (prize1 <= prize2) && (prize1 >= prize3)) {
		return prize1;
	}
	/* Compares to see whether prize2 is the middle */
	else if ((prize2 >= prize1) && (prize2 <= prize3) || (prize2<=prize1) && (prize2 >= prize3)) {
		return prize2;
	}
	/* The only other option means that prize 3 is the middle */
	else {
		return prize3;
	}

}

int FourInARow(int values[], int length)
{
	/* For loop until it reachs the length provided */
	for (int i = 0; i < length; i++) {
		/* Makes sure the last number doesn't go past the length given */
		if ((i+3) < length) {
			/* Checks to see if the next 4 values are the same making a four in a row */
			if (values[i] == values[i + 1] && values[i] == values[i + 2] && values[i] == values[i + 3]) {
				/* If it is four in a row stops the function are returns the first element of the number */
				return i;
			}
		}

	}

	return -1;
}

int BinaryToDecimal(int binary)
{
	/* Save intial value so can be changed */
	int num = binary;
	/* Set the intial value of decimal to zero */
	int dec_value = 0;
	/* Initializing base1 value to 1, i.e 2^0 */
	int base1 = 1;
	/* Save intial value so can be changed later */
	int temp = num;
	/* While loop which runs as long as the binary number is above zero */
	while (temp > 0)
	{
		/* Finding the last value so can be worked backwards */
		int last_digit = temp % 10;
		temp = temp / 10;
		/* Adding the powered numbers together in order to get the final decimal value */
		dec_value += last_digit * base1;
		/* Increase the base for the next value */
		base1 = base1 * 2;
	}

	return dec_value;
}

double MedianAbility(double abilities[], int length)
{
	/* Make j and k interger */
	int j, k;
	/* Make temp a double as it need to hold a double */
	double temp;
	/* Make sum a double as it need to hold a double */
	double sum = 0;
	/* For loop which runs till it reaches the length provided */
	for (j = 0; j < length; ++j)
	{
		/* For loop which is one more than j */
		for (k = j + 1; k < length; ++k)
		{
			/* Checks to see if the current value is greater than the value one up */
			if (abilities[j] > abilities[k])
			{
				/* Change temp to the number stored in 'abilities' array */
				temp = abilities[j];
				/* Make the current value to the value one up */
				abilities[j] = abilities[k];
				/* Make the value one up to the current value */
				abilities[k] = temp;
			}
		}
	}
	/* Checks to see if the lenght provided is even */
	if (length % 2 == 0) {
		/* Mean of the length provided */
		int mean = length / 2;
		/* Average of the two middle values */
		sum = (abilities[mean] + abilities[mean - 1]) / 2;
		return sum;
	}
	/* If it is not even then it must be odd */
	else {
		/* Mean of the length provided */
		int mean = length / 2;
		/* The middle is just the mean */
		sum = abilities[mean];
		return sum;
	}
	
}

void RemoveSpaces(char *name)
{
	/* Destination to copy to */
	char *dest = name;  
	/* While loop which runs till it reaches the end of the string */
	while (*name != '\0')
	{
		/* Loop to identify if the current and next character is a space*/
		while (*name == ' ' && *(name + 1) == ' ')
			/* Go to next character */
			name++;  
		*dest++ = *name++;
	}

	/* Make sure the string is properly terminated */
	*dest = '\0';
}

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int i, j;
	/* For loop to create a board */
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			board[i][j] = 0;
		}
	}
	/* If the array or board is even then make four points in the middle */
	if (size % 2 == 0) {
		int mean = size / 2;
		/* 3 is the fixed point */
		board[mean-1][mean-1] = 3;
		board[mean-1][mean] = 3;
		board[mean][mean-1] = 3;
		board[mean][mean] = 3;
	}
	/* If the array is odd then make one center point */
	else {
		int mean = size / 2;
		/* 3 is the fixed point */
		board[mean][mean] = 3;
	}
}

void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{
	*lastRow = 0;
	*lastCol = 0;
	int count = 0;
	int i;
	/* Check which side to use */
	switch (side) {
		/* Dropped from the top */
		case 'N':
			/* For loop which loops for the size of the board */
			for (i = 0; i < size; i++) {
				/* If there is a fixed point or an already placed point it will be placed before it  */
				if (board[i][move] == 3 || board[i][move] == 2 || board[i][move] == 1) {
					*lastRow = i - 1;
					*lastCol = move;
					board[*lastRow][*lastCol] = player;
					/* Count goes up so that another token is not placed */
					count = 1;
					break;
				}

			}
			/* If count is zero that means that there is no obstacle therefore goes to the end */
			if (count == 0) {
				*lastRow = size - 1;
				*lastCol = move;
				board[*lastRow][*lastCol] = player;
			}
			break;
		/* Dropped form the left side */
		case 'W':
			/* For loop which loops for the size of the board */
			for (i = 0; i < size; i++) {
				/* If there is a fixed point or an already placed point it will be placed before it  */
				if (board[move][i] == 3 || board[move][i] == 2 || board[move][i] == 1) {
					*lastRow = move;
					*lastCol = i - 1;
					board[*lastRow][*lastCol] = player;
					/* Count goes up so that another token is not placed */
					count = 1;
					break;
				}
			}
			/* If count is zero that means that there is no obstacle therefore goes to the end */
			if (count == 0) {
				*lastRow = move;
				*lastCol = size - 1;
				board[*lastRow][*lastCol] = player;
			}
			break;
		/* Dropped from the bottom */
		case 'S':
			/* For loop which loops for the size of the board */
			for (i = size - 1; i > -1; i--) {
				/* If there is a fixed point or an already placed point it will be placed before it  */
				if (board[i][move] == 3 || board[i][move] == 2 || board[i][move] == 1) {
					*lastRow = i + 1;
					*lastCol = move;
					board[*lastRow][*lastCol] = player;
					/* Count goes up so that another token is not placed */
					count = 1;
					break;
				}

			}
			/* If count is zero that means that there is no obstacle therefore goes to the end */
			if (count == 0) {
				*lastRow = 0;
				*lastCol = move;
				board[*lastRow][*lastCol] = player;
			}
			break;
		/* Dropped from the right */
		case 'E':
			/* For loop which loops for the size of the board */
			for (i = size - 1; i > -1; i--) {
				/* If there is a fixed point or an already placed point it will be placed before it  */
				if (board[move][i] == 3 || board[move][i] == 2 || board[move][i] == 1) {
					*lastRow = move;
					*lastCol = i + 1;
					board[*lastRow][*lastCol] = player;
					/* Count goes up so that another token is not placed */
					count = 1;
					break;
				}

			}
			/* If count is zero that means that there is no obstacle therefore goes to the end */
			if (count == 0) {
				*lastRow = move;
				*lastCol = 0;
				board[*lastRow][*lastCol] = player;
			}
			break;

	}

}

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	int win = 0;
	int count = 0;
	
	int i, j, x;

	/* For loop that only loops 4 times as thats the amount of time you need the number in a row or diagonal to win */
	for (i = 0; i < 4; i++) {
		/* To check if there are any other same tokens horizontally */
		if (board[row][col + i] == player || board[row][col - i] == player) {
			/* For loop to check the entire col */
			for (j = 0; j < 4; j++) {
				/* If there is a same token right or left from the last token then add 1 to win */
				if (board[row][col + j] == player || board[row][col - j] == player) {
					win++;
				}
				/* If there is no token right or left from the last token then it stops */
				else {
					break;
				}
			}
			/* If the last token is placed in the middle of a 4 in a row */
			if (win >= 4) {
				return player;
			}
			win = 0;
			
		}
		/* To check if there are any other same tokens vertically  */
		else if (board[row + i][col] == player || board[row - i][col] == player) {
			/* For loop to check the entire col */
			for (j = 0; j < 4; j++) {
				/* If there is a same token upwards or downwards from the last token then add 1 to win */
				if (board[row + j][col] == player || board[row - j][col] == player) {
					win++;
				}
				/* If there is no token upwards or downwards from the last token then it stops */
				else {
					break;
				}
			}
			/* If the last token is placed in the middle of a 4 in a row */
			if (win >= 4) {
				return player;
			}
			win = 0;
			
		}
		/* To check if there are any other same tokens diagonally from right top to left bottom  */
		else if (board[row + i][col - i] == player || (board[row - i][col + i] == player)) {
			/* For loop to check diagonally */
			for (j = 0; j < 4; j++) {
				/* If there is a same token right top to left bottom from the last token then add 1 to win */
				if (board[row + j][col - j] == player || board[row - j][col + j] == player) {
					win++;
				}
				/* If there is no token diagonally from right top to left bottom from the last token then it stops */
				else {
					break;
				}
			}
			/* If the last token is placed in the middle of a 4 in a row */
			if (win >= 4) {
				return player;
			}

			win = 0;
		}
		
		/* To check if there are any other same tokens diagonally from left top to right bottom  */
		else if (board[row + i][col + i] == player || board[row - i][col - i] == player) {
			/* For loop to check diagonally */
			for (j = 0; j < 4; j++) {
				/* If there is a same token left top to right bottom from the last token then add 1 to win */
				if (board[row + j][col + j] == player || board[row - j][col - j] == player) {
					win++;
				}
				/* If there is no token diagonally from left top to right bottom from the last token then it stops */
				else {
					break;
				}
			}
			/* If the last token is placed in the middle of a 4 in a row */
			if (win >= 4) {
				return player;
			}
			win = 0;
		}
	}
	/* For loop to check if the outer edges are filled */
	for (x = 0; x < size; x++) {
		if (board[0][x] != 0 && board[x][size - 1] != 0 && board[size - 1][(size - 1) - x] != 0 && board[(size - 1) - x][0] != 0) {
			count++;
		}
	}
	/* When count hits the size it means all for sides of the board is filled therefore the last player is the winner */
	if (count == size) {
		return player;
	}
	
	/* If its not 4 then the last player is not the winner */
	return 0;

}

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	
	int i, j, k, l;
	/* A vaule so which will be the postion in the string */
	int count = 0;
	/* Loop that makes 2 dashes at the start */
	for (k = 0; k < 2; k++) {
		boardString[count] = '-';
		count++;
	}
	/* Loop that places the North letter */
	for (l = 0; l < size; l++) {
		boardString[count] = 'N';
		count++;
	}
	/* Loop that makes 2 dashes at the end */
	for (k = 0; k < 2; k++) {
		boardString[count] = '-';
		count++;
	}
	boardString[count] = '\n';
	count++;
	/* Loop that makes 2 dashes at the start */
	for (k = 0; k < 2; k++) {
		boardString[count] = '-';
		count++;
	}
	/* Loop that places the number of col */
	for (l = 0; l < size; l++) {
		boardString[count] = (char)l + '0';
		count++;
	}
	/* Loop that makes 2 dashes at the end */
	for (k = 0; k < 2; k++) {
		boardString[count] = '-';
		count++;
	}
	/* Makes a new line */
	boardString[count] = '\n';
	count++;
	/* Loop to create the string */
	for (i = 0; i < size; i++) {
		/* Places the West letter */
		boardString[count] = 'W';
		count++;
		/*  Places the number of row */
		boardString[count] = (char)i + '0';
		count++;
		for (j = 0; j < size; j++) {
			/* When the board has a zero make a string with '.' for empty */
			if (board[i][j] == 0) {
				boardString[count] = '.';
				count++;
			}
			/* When the board has a 3 make a string with '#' for fixed */
			else if (board[i][j] == 3) {
				boardString[count] = '#';
				count++;
			}
			/* When the board has a 1 make a string with 'X' for player one */
			else if (board[i][j] == 1) {
				boardString[count] = 'X';
				count++;
			}
			/* When the board has a 2 make a string with 'O' for player two */
			else if (board[i][j] == 2) {
				boardString[count] = 'O';
				count++;
			}

		}
		/* Places number of row */
		boardString[count] = (char)i + '0';
		count++;
		/* Places the East letter */
		boardString[count] = 'E';
		count++;
		/* Makes a new line afther a row */
		boardString[count] = '\n';
		count++;
	}
	/* Loop that makes 2 dashes at the start */
	for (k = 0; k < 2; k++) {
		boardString[count] = '-';
		count++;
	}
	/* Loop that places the number of col */
	for (l = 0; l < size; l++) {
		boardString[count] = (char)l + '0';
		count++;
	}
	/* Loop that makes 2 dashes at the end */
	for (k = 0; k < 2; k++) {
		boardString[count] = '-';
		count++;
	}
	/* Makes a new line */
	boardString[count] = '\n';
	count++;
	/* Loop that makes 2 dashes at the start */
	for (k = 0; k < 2; k++) {
		boardString[count] = '-';
		count++;
	}
	/* Loop that places the South letter */
	for (l = 0; l < size; l++) {
		boardString[count] = 'S';
		count++;
	}
	/* Loop that makes 2 dashes at the end */
	for (k = 0; k < 2; k++) {
		boardString[count] = '-';
		count++;
	}
	/* Makes a new line */
	boardString[count] = '\n';
	count++;
	/* Puts an end to the string */
	boardString[count] = '\0';
}

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	int random_point, random_direction;
	/* Gets a random number form 0 to the max */
	random_point = rand() % size;
	/* Gets a random number between 0 and 3 to get a random side*/
	random_direction = rand() % 4;
	/* If its 0 then N */
	if (random_direction == 0) {
		*side = 'N';
		*move = random_point;
	}
	/* If its 0 then E */
	if (random_direction == 1) {
		*side = 'E';
		*move = random_point;
	}
	/* If its 0 then S */
	if (random_direction == 2) {
		*side = 'S';
		*move = random_point;
	}
	/* If its 0 then W */
	if (random_direction == 3) {
		*side = 'W';
		*move = random_point;
	}	
}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	int random_point, random_direction;
	/* Gets a random number form 0 to the max */
	random_point = rand() % size;
	/* Gets a random number between 0 and 3 to get a random side*/
	random_direction = rand() % 4;
	/* If its 0 then N */
	if (random_direction == 0) {
		*side = 'N';
		*move = random_point;
	}
	/* If its 0 then E */
	if (random_direction == 1) {
		*side = 'E';
		*move = random_point;
	}
	/* If its 0 then S */
	if (random_direction == 2) {
		*side = 'S';
		*move = random_point;
	}
	/* If its 0 then W */
	if (random_direction == 3) {
		*side = 'W';
		*move = random_point;
	}
}
