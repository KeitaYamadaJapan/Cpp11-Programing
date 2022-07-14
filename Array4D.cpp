//
//  main.cpp
//  CPeking_CS3_W07_Q1-Array4D-Obj
//
//  Created by 山田啓太 on 2022/07/12.
//

#include <iostream>
using namespace std;

template<class T>
class Obj{
private:
    T *a;
public:
    Obj(int a1){
        a = new T[a1];
    }
    T &operator[](int s){
        return a[s];
    }
    T &operator=(const T b){
        this->a = b;
        return *this;
    }
};

template<class T>
class Array2D{
private:
    Obj<T> **obj;
public:
    Array2D(int m, int n){
        obj = new Obj<T>*[m];
        for(int i = 0; i < m; i++){
            obj[i] = new Obj<T>(n);
        }
    }
    Obj<T> &operator[](int i){
        return *obj[i];
    }
};

template<class T>
class Array3D{
private:
    Array2D<T> **arr2;
public:
    Array3D(int m, int n, int o){
        arr2 = new Array2D<T> *[m];
        for(int j = 0; j < m; j++){
            arr2[j] = new Array2D<T> (n, o);
        }
    }
    Array2D<T> &operator[](int j){
        return *arr2[j];
    }
};

template<class T>
class Array4D{
private:
    Array3D<T> **arr3;
public:
    Array4D(int m, int n, int o, int p){
        arr3 = new Array3D<T> *[m];
        for(int k = 0; k < m; k++){
            arr3[k] = new Array3D<T>(n,o,p);
        }
    }
    Array3D<T> &operator[](int k){
        return *arr3[k];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Obj<int> obj(5);
    int num = 0;
    for(int i = 0; i < 5; i++){
        obj[i] = num++;
    }
    for(int i = 0; i < 5; i++){
        cout << obj[i] << " " ;
    }
    cout << endl;
    num = 100;
    Array4D<int> a(2,3,4,5);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 5; l++){
                    a[i][j][k][l] = num++;
                }
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 5; l++){
                    cout << a[i][j][k][l] << " ";
                }
            }
        }
    }
    cout << endl;
    return 0;
}
