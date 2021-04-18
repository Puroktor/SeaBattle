#include <iostream>
#include <iomanip> 

using std::cin;
using std::setw;
using std::endl;
using std::cout;

bool tryToPlace(int n, int m, int* available, int** mat) {
    int countPlaced = 0;
    for (int i = m; i > 0; i--)
        for (int j = 0; j <= m - i; j++)
        {
            bool placed = false;
            for (int k = 0; k < n; k++)
            {
                if (available[k] >= i) {
                    countPlaced++;
                    for (int z = n - available[k]; z < n - available[k] + i; z++)
                        mat[z][k] = countPlaced;
                    available[k] -= i + 1;
                    placed = true;
                    break;
                }
            }
            if (!placed)
                return false;
        }
    return true;
} // O(m^2 * n^2)

int main()
{
    int n, m;
    setlocale(LC_ALL, "Russian");
    cin >> n >> m;
    int* available = new int[n];
    for (int i = 0; i < n; i += 2)
        available[i] = n;
    int** mat = new int* [n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;
    }
    if (tryToPlace(n, m, available, mat))
    {
        cout << "Можно разместить" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(5) << mat[i][j];
            cout << endl;
        }
    }
    else
        cout << "Нельзя разместить";

    delete[] available;
    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
}
