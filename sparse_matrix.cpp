#include<iostream>
using namespace std;

int main(){
    int row, col , non_zero;
    int sparse[100][3];
    int matrix[100][100];
    int i, j, k =1;

    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;


    cout<<"Enter the number of non-zero elements: "<<non_zero<<endl;
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


    cout<<"The sparse matrix representation is: "<<endl;
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

return 0;
}
