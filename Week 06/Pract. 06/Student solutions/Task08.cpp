#include <iostream>

void fillArray(size_t (*array)[10], const size_t ROWS, const size_t COLS)
{
	for (size_t i = 0; i < ROWS; ++i)
	{
		for (size_t j = 0; j < COLS; ++j)
		{
			std::cin >> array[i][j];
		}
	}
}

void printArray(size_t (*array)[10], const size_t ROWS, const size_t COLS)
{
	for (size_t i = 0; i < ROWS; ++i)
	{
		for (size_t j = 0; j < COLS; ++j)
		{
			std::cout << array[i][j] << " ";
		}

		std::cout << std::endl;
		}
}

void makeArrayCopy(size_t (*array)[10], size_t (*resultArray)[10], const size_t ROWS, const size_t COLS)
{
	for (size_t i = 0; i < ROWS; ++i)
	{
		for (size_t j = 0; j < COLS; ++j)
		{
			 resultArray[i][j] = array[i][j];
		}
	}
}

size_t findNeighbour(const int COORDINATE_ROW, const size_t SIZE, const int PREV = 0)
{
	int neighbour = COORDINATE_ROW;


	if (neighbour - 1 >= 0 && PREV)
	{
		neighbour--;
	}

	if (neighbour + 1 <= SIZE && !PREV)
	{
		neighbour++;
	}

	return neighbour;
}

void addCoordsToBounds(size_t (*array)[2], size_t &arrayLimitRow, const size_t COLS_SIZE, const size_t ROWS_SIZE, int iindex, int jindex)
{
	array[arrayLimitRow][0] = iindex;
	array[arrayLimitRow++][1] = findNeighbour(jindex, COLS_SIZE, 1);
	array[arrayLimitRow][0] = iindex;
	array[arrayLimitRow++][1] = findNeighbour(jindex, COLS_SIZE);

	array[arrayLimitRow][0] = findNeighbour(iindex, ROWS_SIZE, 1);
	array[arrayLimitRow++][1] = jindex;
	array[arrayLimitRow][0] = findNeighbour(iindex, ROWS_SIZE);
	array[arrayLimitRow++][1] = jindex;
}

void clearBoundsArray(size_t (*array)[2], size_t &arrayLimitRow, const size_t COLS)
{
	for (size_t i = 0; i < arrayLimitRow; ++i)
	{
		for (size_t j = 0; j < COLS; ++j)
		{
			 array[i][j] = 0;
		}
	}

	arrayLimitRow = 0;
}

size_t countGroups(size_t (*array)[10], size_t (*bounds)[2], const size_t ROWS, const size_t COLS, const size_t NEW_COLS = 2)
{
	const size_t MAX_SIZE = 10;
	size_t copyArray[MAX_SIZE][MAX_SIZE];

	size_t boundsLimitHeight = 0;

	size_t group = 0;

	makeArrayCopy(array, copyArray, ROWS, COLS);

	for (size_t i = 0; i < ROWS; ++i)
	{
		for (size_t j = 0; j < COLS; ++j)
		{
			if (copyArray[i][j])
			{
				copyArray[i][j] = 0;
				group++;
				size_t neighbourLimit = 0;

				addCoordsToBounds(bounds, boundsLimitHeight, ROWS, COLS, i, j);

				while (neighbourLimit < boundsLimitHeight)
				{
					if (copyArray[bounds[neighbourLimit][0]][bounds[neighbourLimit][1]])
					{
						copyArray[bounds[neighbourLimit][0]][bounds[neighbourLimit][1]] = 0;
						addCoordsToBounds(bounds, boundsLimitHeight, ROWS, COLS, bounds[neighbourLimit][0], bounds[neighbourLimit][1]);
					}

					++neighbourLimit;
				}

				clearBoundsArray(bounds, boundsLimitHeight, NEW_COLS);
			}
		}
	}

	return group;
}

void main()
{
	const size_t MAX_SIZE = 10;
	const size_t MAX_BOUNDS_COLS = 2;
	const size_t MAX_COORDINATES = 4;
	size_t numbersData[MAX_SIZE][MAX_SIZE];
	size_t bounds[MAX_SIZE*MAX_SIZE*MAX_COORDINATES][MAX_BOUNDS_COLS];
	size_t numbersRows = 0;
	size_t numbersCols = 0;
	std::cin >> numbersRows >> numbersCols;

	// 
	// size_t numbersRows = 4;
	// size_t numbersCols = 6;
	// size_t numbersData[MAX_SIZE][MAX_SIZE] = {{0, 1, 1, 0, 0, 0},
	// 																																										{1, 1, 0, 1, 1, 0},
	// 																																										{0, 0, 0, 0, 0, 1},
	// 																																										{1, 1, 1, 1, 1, 0}};
	// 

	fillArray(numbersData, numbersRows, numbersCols);
	size_t groups = countGroups(numbersData, bounds, numbersRows, numbersCols);
	std::cout << groups;
}