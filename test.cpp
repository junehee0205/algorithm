#include <iostream>
#include <array>
#include <vector>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> ten = {35, 4, 23, 45, 6, 90, 13, 22, 0, 77};
vector<int> twenty = {35, 4, 23, 49, 6, 97, 13, 22, 0, 77, 45, 3, 25, 90, 44, 28, 18, 29, 34, 132};

int * insertsort(array array, int n) {
    for (int i = 1; i < n; i++) {
        int tmp = array[i];
        int j = 0;
        for (j = i - 1; j > -1; j--) {
            if (array[j] > tmp) {
                array[j+1] = array[j];
            }
            else {
                break;
            }
        }
        array[j+1] = tmp;
    }
    return array;
}

/*int size(int array[]){
        return sizeof array /sizeof array[0];
}*/

int main(){
//      insertsort(ten, size(ten));
//      insertsort(twenty, size(twenty);

        insertsort(ten, ten.size());
        insertsort(twenty, twenty.size());

        for(int i=0; i<ten.size(); i++){
                cout << "ten[" << i << "] = " << ten[i] << "\n";
        }

        for(int i=0; i<twenty.size(); i++){
                cout << "twenty[" << i << "] = " << twenty[i] << "\n";
        }
        return 0;
}