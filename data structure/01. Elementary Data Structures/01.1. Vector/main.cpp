#include <iostream>

using namespace std;

extern "C" int* StaticImmutableVector();
extern "C" int GeneratedStars(long num);

int main() {

    int* vector = StaticImmutableVector();
    int i = 0;
    cout << "vector: ";

    while (true) {
        if(vector[i] == -1) {
            cout << endl;
            cout << "size: " << i;
            cout << endl;
            break;
        }
        cout << vector[i] << " ";
        i++;
    }


  return 0;

}
