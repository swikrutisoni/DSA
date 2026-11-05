#include<iostream>
using namespace std;

#define MAX 50

struct Sparse
{
    int row;
    int col;
    int value;
};

void create(Sparse a[])
{
    int r, c, n = 0;

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> c;

   
    cout << "Enter elements of matrix:\n";

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int x;
            cin >> x;

            if (x != 0)
            {
                n++;
                a[n].row = i;
                a[n].col = j;
                a[n].value = x;
            }
        }
    }
}

int main()
{
    Sparse a[MAX];
    create(a);
    return 0;
}
}
