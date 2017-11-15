// Program Chart2 manipulates a two-dimensional array
// variable.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ROW_MAX = 8;
const int COL_MAX = 10;

typedef int ItemType;

typedef ItemType ChartType[ROW_MAX][COL_MAX];		//y by x

void GetChart(ifstream& data, ChartType &chart, int& rowsUsed, int& colsUsed)		// Reads values and stores them in the chart.
	// Pre:  rowsUsed and colsUsed are on the first line of
	//       file data; values are one row per line
	//       beginning with the second line.
	// Post: Values have been read and stored in the chart.

{
	ItemType  item;
	data >> rowsUsed >> colsUsed;

	for(int row = 0; row < rowsUsed; row++)
	{
		for(int col = 0; col < colsUsed; col++)
			// FILL IN Code to read and store the next value.
		{
			data >> item;
			chart[row][col] = item;
		}
	}
}

void  PrintChart(ofstream& data, const ChartType chart, int rowsUsed, int colsUsed)		// Writes values in the chart to a file.
	// Pre:  The chart contains valid data.
	// Post: Values in the chart have been sent to a file by row,
	//       one row per line.
{
	// FILL IN Code to print chart by row.
	for(int row = 0; row < rowsUsed; row++)
	{
		for(int col = 0; col < colsUsed; col++)
		{
			data << chart[row][col] << setw(3);
		}
		data << setw(0) << endl;
	}
}

int getLargest(ChartType chart, int rowsUsed, int colsUsed)	//Returns the largest value in a chart
{
	int max = chart[0][0];	//Intialize the variable
	for(int row = 0; row < rowsUsed; row++)
	{
		for(int col = 0; col < colsUsed; col++)
		{
			if(chart[row][col] > max) max = chart[row][col];
		}
	}
	return max;
}

int  main()
{
	cout << "Processing data..." << endl;
	ChartType chart;
	int rowsUsed;
	int colsUsed;
	ifstream dataIn;
	ofstream dataOut;

	dataIn.open("chart2.dat");
	dataOut.open("chart2.out");
	GetChart(dataIn, chart, rowsUsed, colsUsed);
	PrintChart(dataOut, chart, rowsUsed, colsUsed);
	
	cout << "Largest value is: " << getLargest(chart, rowsUsed, colsUsed) << endl;

	cout << "Done!  Press enter key to end." << endl;
	cin.get();
	return 0;
}