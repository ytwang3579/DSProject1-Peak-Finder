#include <iostream>
#include <fstream>

#define M (m+2)
#define N (n+2)

using namespace std;

int main(int argc, char* argv[])
{
    ofstream outfile("final.peak");
    if(argc != 2){
        cout << "Input Error!!\n";
        return 1;
    }
    ifstream infile(argv[1]);
    if(!infile){
        cout << "Cannot open file!!\n";
        return 1;
    }

    int m, n;
    infile >> m >> n;
    cout << m << " " << n << '\n';

    int matrix[M*N];

// set edges to be INT32_MIN
    for(int i=0; i<=m+1; i++){
        matrix[i*N] = matrix[i*N+N-1] = INT32_MIN; //matrix[i][0] matrix[i][n+1]
    }
    for(int i=1; i<=n; i++){
        matrix[i] = matrix[(M-1)*N+i] = INT32_MIN; //matrix[0][i] matrix[m+1][i]
    }

// read input to matrix
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            infile >> matrix[i*N+j];
        }
    }

// print matrix
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            outfile << matrix[i*N+j] << " ";
        }
        outfile << '\n';        
    }

    return 0;
}