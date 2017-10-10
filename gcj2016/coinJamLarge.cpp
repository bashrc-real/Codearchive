// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
using namespace std;
void Solve(int N, int J) {
    while (J--){
        cout << "11";
        for (int i = 0; i < (N - 4) >> 1; ++i) {
            cout << ((J&(1 << i)) ? "11" : "00");
        }
        cout << "11 ";
        for (int i = 2; i <= 10; ++i) cout << i + 1 << " ";
        cout << endl;
    }
}

int main()
{
    cout << "Case #1:"<<endl;
    Solve(32, 500);
    return 0;
}

