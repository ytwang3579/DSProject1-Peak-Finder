#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#define M 3
#define N (n+2)
#define TARGET0 i
#define TARGET1 (i+N)
#define TARGET2 (i+N*2)


using namespace std;
ifstream infile;
ofstream outfile;

void findpeak(vector<int>& matrix, const int m, const int n)
{
    vector<int> peakcnt_i, peakcnt_j;
    int current_row[3] = {0, -2, -1};
    int rowptr = 1;

    //initialization
    for(int i=1; i<=n; i++){
        matrix[TARGET0] = INT32_MIN;
        infile >> matrix[TARGET1];
    }

    while(current_row[(rowptr==0) ? 2 : (rowptr==1) ? 0 : 1]<m){
        switch(rowptr){
        case 0:
            current_row[rowptr] += 3;

            if(current_row[rowptr]!=m) for(int i=1; i<=n; i++) infile >> matrix[TARGET1];
            else for(int i=1; i<=n; i++) matrix[TARGET1] = INT32_MIN;

            for(int i=1; i<=n; i++){
                if(matrix[TARGET0]>=matrix[TARGET0+1] && matrix[TARGET0]>=matrix[TARGET0-1]
                && matrix[TARGET0]>=matrix[TARGET0+N] && matrix[TARGET0]>=matrix[TARGET0+2*N]){
                    peakcnt_i.push_back(current_row[rowptr]);
                    peakcnt_j.push_back(i);
                }
            }
            rowptr = 1;
            break;
        case 1:
            current_row[rowptr] += 3;

            if(current_row[rowptr]!=m) for(int i=1; i<=n; i++) infile >> matrix[TARGET2];
            else for(int i=1; i<=n; i++) matrix[TARGET2] = INT32_MIN;

            for(int i=1; i<=n; i++){
                if(matrix[TARGET1]>=matrix[TARGET1+1] && matrix[TARGET1]>=matrix[TARGET1-1]
                && matrix[TARGET1]>=matrix[TARGET1+N] && matrix[TARGET1]>=matrix[TARGET1-N]){
                    peakcnt_i.push_back(current_row[rowptr]);
                    peakcnt_j.push_back(i);
                }
            }
            rowptr = 2;
            break;
        case 2:
            current_row[rowptr] += 3;

            if(current_row[rowptr]!=m) for(int i=1; i<=n; i++) infile >> matrix[TARGET0];
            else for(int i=1; i<=n; i++) matrix[TARGET0] = INT32_MIN;

            for(int i=1; i<=n; i++){
                if(matrix[TARGET2]>=matrix[TARGET2+1] && matrix[TARGET2]>=matrix[TARGET2-1]
                && matrix[TARGET2]>=matrix[TARGET2-N] && matrix[TARGET2]>=matrix[TARGET2-2*N]){
                    peakcnt_i.push_back(current_row[rowptr]);
                    peakcnt_j.push_back(i);
                }
            }
            rowptr = 0;
            break;
        }
    }
    
    outfile << peakcnt_i.size() << '\n';
    
    for(int i=0; i<peakcnt_i.size(); i++){
        outfile << peakcnt_i[i] << " " << peakcnt_j[i] << '\n';
    }
    
}

int main(int argc, char* argv[])
{
    if(argc != 2){
        cout << "Input Error!!\n";
        return 1;
    }
    stringstream str;
    stringstream strout;
    str << "./" << argv[1] << "/matrix.data";
    strout << "./" << argv[1] << "/final.peak";

    outfile.open(strout.str());
    infile.open(str.str());

    if(!infile){
        cout << "Cannot open file!!\n";
        return 1;
    }
    if(!outfile){
        cout << "Cannot write file!!\n";
        return 1;
    }

    int m, n;
    infile >> m >> n;

    vector<int> matrix;
    matrix.reserve(M*N);

    //set edges to be INT32_MIN
    for(int i=0; i<3; i++){
        matrix[i*N] = matrix[(i+1)*N-1] = INT32_MIN;
    }

    findpeak(matrix, m, n);

    return 0;
}