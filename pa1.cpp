#include <iostream>
using namespace std;

void addColumns (int **magicSquare, int size) {
	int sum = 0;
	int value = 0;
	cout << "Sum of Columns: ";
	for (int i = 0; i < size; i++) {
		sum = 0;
		for (int j = 0; j < size; j++) {
			value = magicSquare[j][i];
			sum += value;
		}
		cout << sum << ", ";
	}
	cout << endl;
}

void addRows (int **magicSquare, int size) {
	int sum = 0;
		int value = 0;
		cout << "Sum of Rows: ";
		for (int i = 0; i < size; i++) {
			sum = 0;
			for (int j = 0; j < size; j++) {
				value = magicSquare[i][j];
				sum += value;
			}
			cout << sum << ", ";
		}
		cout << endl;
}

void addDiagonals (int **magicSquare, int size) {
	int sum = 0;
	int value = 0;
	int diagonalNumber = 1;
	cout << "Sum of Diagonals: ";
	while (diagonalNumber <= 2) {
		int j = 0;
		sum = 0;
		switch (diagonalNumber) {
		//Adds the first diagonal (going from top left to bottom right)
		case 1:
			for (int i = 0; i < size; i++, j++) {
				value = magicSquare[i][j];
				sum += value;
			}
			cout << sum << ", ";
			break;
		//Adds the second diagonal (going from bottom left to top right).
		case 2:
			for (int i = 0; i < size; i++, j++) {
				value = magicSquare[i][(size - 1) - j];
				sum += value;
			}
			cout << sum << ", ";
			break;
		}
		diagonalNumber++;
	}
	cout << endl;
}

void printMagicSquare (int **magicSquare, int size, int squareNum) {
	cout << "Magic Square #" << squareNum << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << magicSquare[i][j] << "   ";
		}
		cout << endl;
	}
	addColumns(magicSquare, size);
	addRows(magicSquare, size);
	addDiagonals(magicSquare, size);
	cout << endl;
}

//It creates odd-numbered magic squares by starting at the middle of the 1st row 
//and going 1 up and 1 to the right. Works for any odd-numbered magic Square.
//I learned this method from this website: http://www.1728.org/magicsq1.htm.
int** createMagicSquare(int size) {
	int** oddSquare = new int*[size];
	for (int i = 0; i < size; i++) {
		oddSquare[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			oddSquare[i][j] = 0;
		}
	}
	int row = 0;
	int col = size / 2;
	oddSquare[row][col] = 1;
	//Cycle through the matrix by going 1 up and 1 right. This for loop does that.
	for (int number = 2; number <= (size * size); number++) {
		int initialRow = row;
		int initialCol = col;
		row -= 1;
		col += 1;
		//If it ends up going up and past the matrix, this loops it back to the bottom.
		if (row < 0 && col < size) {
			row = size - 1;
		}
		//If it ends up going to the right and past the matrix, this loops it back to the left.
		else if (col >= size && row >= 0) {
			col = 0;
		}
		//If it goes past the top right corner and goes out of the matrix, this loops it back
		//to the bottom left corner.
		else if (row < 0 && col >= size) {
			row = size - 1;
			col = 0;
		}
		//This checks if the space is already occupied with a number. If it does, then instead
		//of going 1 up and 1 right, it just goes 1 down instead.
		if (oddSquare[row][col] != 0) {
			row = initialRow;
			col = initialCol;
			row += 1;
		}
		oddSquare[row][col] = number;
	}
	return oddSquare;
}

//Creates two matrices and adds them together to create the desired magic square.
//Only works for odd magic squares that are NOT divisible by 3. 
//I learned the method from this video: https://www.youtube.com/watch?v=90pzQ3pRQcg
int** createMagicSquare2(int** magicSquare, int size) {
	int **array1 = new int*[size];
	int **array2 = new int*[size];
	for (int i = 0; i < size; i++) {
		array1[i] = new int[size];
		array2[i] = new int[size];
	}
	int numbers = 1;
	int col = 0;
	//The first row of the 1st array is filled with numbers
	//1 to whatever the size is.
	for (int i = 0; i < size; i++, numbers++) {
		array1[0][i] = numbers;
	}
	col = size - 2;
	//This loop fills the next rows by copying the row before it
	//and shifting that row by 2 to the right (looping back if 
	//it goes out of the matrix).
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (col >= size) {
				col = 0;
			}
			array1[i][j] = array1[i - 1][col];
			col++;
		}
	}
	numbers = 0;
	//The first row of the 2nd array is filled with multiples of
	//whatever the size is starting with 0 (for example, if the size is 7,
	//then it is filled with 0, 7, 14, 28, 35, 42, 49).
	for (int i = 0; i < size; i++, numbers += size) {
		array2[0][i] = numbers;
	}
	col = size - 3;
	//The loop fills the next rows by copying the row before it
	//and shifting that row by 3 to the right (looping back if
	//it goes out of the matrix).
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (col >= size) {
				col = 0;
			}
			array2[i][j] = array2[i - 1][col];
			col++;
		}
	}
	//Matrix Addition
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			magicSquare[i][j] = array1[i][j] + array2[i][j];
		}
	}
	return magicSquare;
}

//For odd magic squares that have a size that is divisible by 3.
//Similar to method createMagicSquare, except that instead of going 1 up and 1 right,
//this goes 1 down and 1 right.
int** createMagicSquare3(int** magicSquare, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			magicSquare[i][j] = 0;
		}
	}
	int row = (size / 2) + 1;
	int col = size / 2;
	magicSquare[row][col] = 1;
	//Cycles through the matrix by going 1 down and 1 right.
	for (int number = 2; number <= (size * size); number++) {
		int initialRow = row;
		int initialCol = col;
		row++;
		col++;
		//If it goes past the bottom of the matrix, it loops back
		//through the top.
		if (row >= size && col < size) {
			row = 0;
		}
		//If it goes past the right of the matrix, it loops back
		//through the left.
		else if (col >= size && row < size) {
			col = 0;
		}
		//If it goes past the bottom right corner, it loops back
		//through the top left corner.
		else if (row >= size && col >= size) {
			row = 0;
			col = 0;
		}
		//If there is a number already in that spot, then instead of going
		//1 down and 1 right, it goes 2 down (loops back through the top
		//if necessary).
		if (magicSquare[row][col] != 0) {
			row = initialRow;
			col = initialCol;
			row += 2;
			if (row >= size) {
				row = row - (size - 1);
			}
			//If it goes 2 down and there's already a number, it goes 3 down instead.
			if (magicSquare[row][col] != 0) {
				row = initialRow;
				col = initialCol;
				row += 3;
			}
			if (row >= size) {
				row = row - (size + 1);
			}
		}
		magicSquare[row][col] = number;
	}
	return magicSquare;
}

void rotateSquare(int **magicSquare, int size) {
	int **squareCopy = new int*[size];
	for (int i = 0; i < size; i++) {
		squareCopy[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			squareCopy[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j >= 0; j--) {
			squareCopy[i][size - (j + 1)] = magicSquare[j][i];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			magicSquare[i][j] = squareCopy[i][j];
		}
	}
}

void reflectVertically(int **magicSquare, int size) {
	int tempNum = 0;
	for (int col = 0; col < (size / 2); col++) {
		for (int row = 0; row < size; row++) {
			tempNum = magicSquare[row][col];
			magicSquare[row][col] = magicSquare[row][(size - 1) - col];
			magicSquare[row][(size - 1) - col] = tempNum;
		}
	}
}

void reflectHorizontally(int **magicSquare, int size) {
	int tempNum = 0;
	for (int row = 0; row < (size / 2); row++) {
		for (int col = 0; col < size; col++) {
			tempNum = magicSquare[row][col];
			magicSquare[row][col] = magicSquare[(size - 1) - row][col];
			magicSquare[(size - 1) - row][col] = tempNum;
		}
	}
}

void reflectDiagonally1(int **magicSquare, int size) {
	int **squareCopy = new int*[size];
	for (int i = 0; i < size; i++) {
		squareCopy[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			squareCopy[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			squareCopy[i][j] = magicSquare[j][i];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			magicSquare[i][j] = squareCopy[i][j];
		}
	}
}

void reflectDiagonally2(int **magicSquare, int size) {
	int **squareCopy = new int*[size];
	for (int i = 0; i < size; i++) {
		squareCopy[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			squareCopy[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++) {
		for(int j = size; j > 0; j--) {
			squareCopy[i][size - j] = magicSquare[j - 1][size - (i + 1)];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			magicSquare[i][j] = squareCopy[i][j];
		}
	}
}

int main() {
	int **magicSquare;
	int size = 1;
	int squareNum = 1;
	while (size != 0 ) {
		cout << "Enter a size for the Magic Square (Enter 0 to exit): ";
		cin >> size;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Invalid Input. Please Enter an Odd Integer." << endl;
			squareNum = 1;
			size = 1;
			continue;
		}
		if (size != 0 && size % 2 == 0) {
			squareNum = 1;
			cout << "Invalid Input. Please Enter an Odd Integer." << endl;
			continue;
		}
		if (size == 0) {
			continue;
		}
		magicSquare = createMagicSquare(size);
		printMagicSquare(magicSquare, size, squareNum);
		squareNum++;

		for (int i = 0; i < 3; i++) {
			rotateSquare(magicSquare, size);
			printMagicSquare(magicSquare, size, squareNum);
			squareNum++;
		}

		rotateSquare(magicSquare, size);
		reflectVertically(magicSquare, size);
		printMagicSquare(magicSquare, size, squareNum);
		squareNum++;

		reflectVertically(magicSquare, size);
		reflectHorizontally(magicSquare, size);
		printMagicSquare(magicSquare, size, squareNum);
		squareNum++;

		reflectHorizontally(magicSquare, size);
		reflectDiagonally1(magicSquare, size);
		printMagicSquare(magicSquare, size, squareNum);
		squareNum++;

		reflectDiagonally1(magicSquare, size);
		reflectDiagonally2(magicSquare, size);
		printMagicSquare(magicSquare, size, squareNum);
		squareNum++;

		if (size % 3 != 0 && size > 3) {
			magicSquare = createMagicSquare2(magicSquare, size);
			printMagicSquare(magicSquare, size, squareNum);
			squareNum++;

			reflectVertically(magicSquare, size);
			printMagicSquare(magicSquare, size, squareNum);
			squareNum++;
		}
		else if (size > 3) {
			magicSquare = createMagicSquare3(magicSquare, size);
			printMagicSquare(magicSquare, size, squareNum);
			squareNum++;

			reflectVertically(magicSquare, size);
			printMagicSquare(magicSquare, size, squareNum);
			squareNum++;
		}
		squareNum = 1;
	}
	for (int i = 0; i < size; i++) {
		delete[] magicSquare[i];
	}
	delete[] magicSquare;
	cout << "You have shutdown the program" << endl;
	return 0;
}

