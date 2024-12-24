#include <iostream>
using namespace std;

int main()
{
	// INPUT
	int N, Q;
	cin >> N >> Q;

	int array[3][N][N]{};

	// Cheese removal
	for (int i = 0; i < Q; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		array[0][x][y]++;
		array[1][y][z]++;
		array[2][x][z]++;

		// FIND VALUES
		int count = 0;
		for (int i = 0; i < 3; i++)
		{
			for (auto &row : array[i])
			{
				for (auto &col : row)
				{
					if (col == N)
					{
						count++;
					}
				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}
