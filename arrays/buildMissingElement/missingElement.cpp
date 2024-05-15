#include <iostream>

using namespace std;

int main()
{
    int a[] = {1,2,3,4,5,6,8,9,10,11,12};
    int n = 12; // how many should be here
    int sum = 0;

    for(int i = 0; i < 11; i++)
    {
        sum = sum + a[i];
    }

    int S = n * (n+1) / 2;

    int diff = S - sum;

    cout << "Missing number is " << diff << endl;
    cout << "Sum is " << sum << endl;
    cout << "S is " << S << endl;


    return 0;
}

