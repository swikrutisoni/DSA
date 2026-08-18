#include<iostream>
using namespace std;

int main(){
  int row, col , non_zero;
    int sparse[100][3];
    int matrix[100][100];
    int t[100][100];
    int i, j, k =1;

    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;


    cout<<"Enter the number of non-zero elements: "<<endl;
    cin>>non_zero;

    cout<<"enter the matrix elements: "<<endl;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            cin>>matrix[i][j];
        }
    }
    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = non_zero;


    
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(matrix[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }


    cout<<"The sparse matrix representation is: "<<endl;
    for(i=0; i<k; i++){
        cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
}

int transpose[100][3];

// Header
transpose[0][0] = sparse[0][1];
transpose[0][1] = sparse[0][0];
transpose[0][2] = sparse[0][2];

k = 1;

// Transpose
for(i = 0; i < sparse[0][1]; i++)       // Loop through columns
{
    for(j = 1; j <= sparse[0][2]; j++)  // Loop through non-zero elements
    {
        if(sparse[j][1] == i)
        {
            transpose[k][0] = sparse[j][1];
            transpose[k][1] = sparse[j][0];
            transpose[k][2] = sparse[j][2];
            k++;
        }
    }
}

cout << "\nTranspose in Triplet Form:\n";
for(i = 0; i < k; i++)
{
    cout << transpose[i][0] << " "
         << transpose[i][1] << " "
         << transpose[i][2] << endl;
}

return 0;


}