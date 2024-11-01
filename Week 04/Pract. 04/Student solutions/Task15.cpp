#include <iostream>
#include <vector>

void buildMatrix(std::vector< std::vector<int>>& emptyMatrix)
{
	int rowSize = emptyMatrix.size();
	int colSize = emptyMatrix[0].size();

	for (int rowIncrement = 0; rowIncrement < rowSize; ++rowIncrement)
	{
		for (int columnIncrement = 0; columnIncrement < colSize; ++columnIncrement)
		{
			std::cin >> emptyMatrix[rowIncrement][columnIncrement];
		}
	}
}

bool isMultipliable(std::vector< std::vector<int>>& matrixLier, std::vector< std::vector<int>>& matrixLicand)
{
	bool multipliable = 1;
	int firstMatrixCol = matrixLier[0].size();
	int secondMatrixRow = matrixLicand.size();

	if (firstMatrixCol != secondMatrixRow) {
		multipliable = 0;
	}

	return multipliable;
}

void printMatrix(std::vector< std::vector<int>>& matrix)
{
	int rowSize = matrix.size();
	int colSize = matrix[0].size();

	std::cout << "Matrix" << std::endl;

	for (int rowIncrement = 0; rowIncrement < rowSize; ++rowIncrement)
	{
		for (int columnIncrement = 0; columnIncrement < colSize; ++columnIncrement)
		{
			std::cout << matrix[rowIncrement][columnIncrement] << " ";
		}

		std::cout << std::endl;
	}
}

void multiplyMatrices(std::vector< std::vector<int>>& matrixLier, std::vector< std::vector<int>>& matrixLicand)
{
	bool allowed = isMultipliable(matrixLier, matrixLicand);

	if (allowed)
	{
		int resultRows = matrixLier.size();
		int resultCols = matrixLicand[0].size();
		int collectiveSize = matrixLier[0].size();

		std::vector<std::vector<int>> resultMatrix(resultRows, std::vector<int>(resultCols));

		for (int rowIncrement = 0; rowIncrement < resultRows; ++rowIncrement)
		{
			for (int colIncrement = 0; colIncrement < resultCols; ++colIncrement)
			{
				for (int collectiveIncrement = 0; collectiveIncrement < collectiveSize; collectiveIncrement++)
				{
					resultMatrix[rowIncrement][colIncrement] += matrixLier[rowIncrement][collectiveIncrement] * matrixLicand[collectiveIncrement][colIncrement];
				}
			}
		}

		printMatrix(resultMatrix);
		return;
	}
	else
	{
		std::cout << "Matrix multiplication is not possible.";
		return;
	}
}

void main()
{
	int firstMatrixRow = 0;
	int firstMatrixCol = 0;
	int secondMatrixRow = 0;
	int secondMatrixCol = 0;

	std::cout << "N: ";
	std::cin >> firstMatrixRow;
	std::cout << "M: ";
	std::cin >> firstMatrixCol;
	std::vector<std::vector<int>> matrixFirst(firstMatrixRow, std::vector<int>(firstMatrixCol));
	buildMatrix(matrixFirst);

	
	std::cout << "P: ";
	std::cin >> secondMatrixRow;
	std::cout << "Q: ";
	std::cin >> secondMatrixCol;

	std::vector<std::vector<int>> matrixSecond(secondMatrixRow, std::vector<int>(secondMatrixCol));
	buildMatrix(matrixSecond);

	multiplyMatrices(matrixFirst, matrixSecond);
	
	return;
}