#include <iostream>
using namespace std;

int main()
{
	// INPUT
	int N, Q;
	cin >> N >> Q;
	// END INPUT

	int array[3][N][N] = {0};
	// array[0] = xy
	// array[1] = yz
	// array[2] = xz

	// PRINT ARRAY
	for (auto &arr : array)
	{
		for (auto &row : arr)
		{
			for (auto &col : row)
			{
				cout << col << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
	// END PRINT ARRAY

	cout << array[0][1][1];
	return 0;
}