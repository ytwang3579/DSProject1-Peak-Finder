#include <iostream>
using namespace std;

int main()
{
    freopen("matrix.data", "w", stdout);

    cout << "3 999" << endl;

    bool flag = false;
    for(int i=0; i<999; i++){
        if(flag) cout << "87";
        else cout << "78";

        if(i!=998) cout << " ";
        else cout << endl;
        flag = !flag;
    }
    for(int i=0; i<999; i++){
        if(flag) cout << "87";
        else cout << "78";

        if(i!=998) cout << " ";
        else cout << endl;
        flag = !flag;
    }
    for(int i=0; i<999; i++){
        if(flag) cout << "87";
        else cout << "78";

        if(i!=998) cout << " ";
        else cout << endl;
        flag = !flag;
    }
    return 0;
}