#include <iostream>
using namespace std;

int main(){

    int arr[3] = {1, 2, 3};
    int (*arrptr)[3] = &arr;

    cout << arr << endl;
    cout << *arrptr << endl;

    cout << arr[0] << endl;
    cout << (*arrptr)[0] << endl;

        cout << arr[1] << endl;
    cout << (*arrptr)[1] << endl;

        cout << arr[2] << endl;
    cout << (*arrptr)[2] << endl;

    return 0;
}