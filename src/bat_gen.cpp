#include <fstream>
using namespace std;
ifstream input;
ofstream output;

int main(int argc, char* argv[])
{
    input.open("data.txt");
    output.open("check.bat");

    string str;
    while(getline(input, str, '\n')){
        output << "FC .\\" << str << "\\final.peak " << str << "\\final_eff.peak" << endl;
    }
    return 0;
}