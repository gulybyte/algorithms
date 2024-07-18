#include <iostream>
#include <vector>

using namespace std;

int main() {

    int dynamicMutableVector[] = {42, 7, 33, 81};
    int size = sizeof(dynamicMutableVector) / sizeof(dynamicMutableVector[0]);

    cout << "\nValue of indice 0: " << dynamicMutableVector[0];
    cout << "\nSize: " << size;

    dynamicMutableVector[0] = 35;
    dynamicMutableVector[4] = 27;
    dynamicMutableVector[42] = 402;

    int newSize = sizeof(dynamicMutableVector) / sizeof(dynamicMutableVector[0]);

    cout << "\nValue of indice 0: " << dynamicMutableVector[0];
    cout << "\nValue of indice 4: " << dynamicMutableVector[4];
    cout << "\nValue of indice 42: " << dynamicMutableVector[42];
    cout << "\nValue of indice 100: " << dynamicMutableVector[100];
    cout << "\nNew size: " << newSize;

    /* int arr[5];
    for (int i = 0; i < 5; i++){
        arr[i] = i;
        cout << "\n" << arr[i];
    } */

    /*arr[420] = 68;
    cout << "\nValue of indice 420: " << arr[420];*/

    return 0;

}
