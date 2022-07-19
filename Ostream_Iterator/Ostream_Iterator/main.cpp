//
//  main.cpp
//  Ostream_Iterator
//
//  Created by 山田啓太 on 2022/07/16.
//

#include <iostream>
#include <set>
using namespace std;


class MyInteger{
public:
    int num;
    MyInteger(int a): num(a){}
    friend ostream &operator<<(ostream &os,MyInteger obj);
};

ostream &operator<<(ostream &os, MyInteger obj){
    os << obj.num << " ";
    return os;
}

struct comp1{
    bool operator()(const int x, const int y)const{
        return x > y;
    }
};

struct comp3{
    bool operator()(const MyInteger a, const MyInteger b)const{
        return a.num < b.num;
    }
};

template<class T>
class MyDataType{
public:
    T val;
    MyDataType(T t):val(t){}
    friend ostream &operator<<(ostream &os, MyDataType<T> dt);
};

/**
 template<class T>のTをintに固定したostreamを作ったら動いた。
 string, char等を個別に作れば良いと思う。
*/
ostream &operator<<(ostream &os,MyDataType<int> dt){
    os << dt.val << ",";
    return os;
}

ostream &operator<<(ostream &os, MyDataType<string> dt){
    os << dt.val << " ";
    return os;
}

struct compare{
    bool operator()(const MyDataType<int> a, const MyDataType<int> b)const{
        return a.val > b.val;
    }
    bool operator()(const MyDataType<string> a, const MyDataType<string> b)const{
        return (a.val).compare(b.val) > 0;
    }
};


int main() {
    // オリジナル課題部分　開始
    // Original assignment part start
    int a[] = {8,7,8,9,6,2,1};
    set<int> v0(a, a+7);
    ostream_iterator<int> o(cout," " );
    copy(v0.begin(),v0.end(),o);
    cout << endl;
    // オリジナル課題部分　終了
    // Original assignment part end
    
    set<int, comp1> v1(a, a+7);
    copy(v1.begin(), v1.end(),o);
    cout << endl;
    
    set<MyInteger, comp3> v3;
    for(int i = 0; i < 7; i++){
        MyInteger dt(a[i]);
        v3.insert(dt);
        cout << dt;
    }
    cout << endl;
    ostream_iterator<MyInteger> o2(cout);
    copy(v3.begin(), v3.end(), o2);
    cout << endl;
    
    
    
    //set<int, comp2()> v3(a, a+7);

    set<MyDataType<int>, compare> v2;
    for(int i = 0; i < 7; i++){
        MyDataType<int> data(a[i]);
        cout << data;
        v2.insert(data);
    }
    cout << endl;
    ostream_iterator<MyDataType<int>> o3(cout);
    copy(v2.begin(),v2.end(), o3);
    cout << endl;
    
    string b[] = {"hello","good","morning","good","bye","joe","asahi","go"};
    set<MyDataType<string>, compare> v4;
    for(int i = 0; i < 8; i++){
        MyDataType<string> dt(b[i]);
        v4.insert(dt);
    }
    ostream_iterator<MyDataType<string>> o4(cout);
    copy(v4.begin(), v4.end(), o4);
    cout << endl;
    
    return 0;
}

/////////////////////////////////////////////
///structでやる必要がある。operator()の()で入力する。
bool comp2(const int x, const int y){
    return x > y;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
