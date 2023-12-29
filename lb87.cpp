#include <iostream>
#include <map>
#include <vector>
using namespace std; 


template <typename T>
T mostFrequent(vector<T> vec) {
    map<T, int> count;
    for (T i : vec) {
        count[i]++;
    }

    int maxCount = 0;
    T res = vec[0];
    for (auto i : count) {
        if (maxCount < i.second) {
            res = i.first;
            maxCount = i.second;
        }
    }
    return res;
}

template <typename T>
void fillArray(vector<T>& vec, int size) {
    T element;
    for (int i = 0; i < size; i++) {
        cin >> element;
        vec.push_back(element);
    }
}

template <typename T>
void printArray(const vector<T>& vec) {
    for (T i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vecInt;
    fillArray(vecInt, 5);
    printArray(vecInt);
    cout << "Most frequent int: " << mostFrequent(vecInt) << endl;

    vector<char> vecChar;
    fillArray(vecChar, 5);
    printArray(vecChar);
    cout << "Most frequent char: " << mostFrequent(vecChar) << endl;
    
    vector<double> vecDouble;
    fillArray(vecDouble, 5);
    printArray(vecDouble);
    cout << "Most frequent double: " << mostFrequent(vecDouble) << endl;
    
    return 0;
}
