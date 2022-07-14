//  中国の学生さんが作ったComplex classをアレイとして動作させました。

//  编程作业—运算符重载 编程题 ＃1
//  http://www.cnblogs.com/dagon/p/4750535.html
//  POJ C++程序设计 编程题＃1 编程作业—运算符重载
//  class Complex
 #include <iostream>
 #include <cstring>
 #include <cstdlib>
 using namespace std;
 class Complex {
 public:
     double r,i;
 public:
     void Print() {
         cout << r << "+" << i << "i" << endl;
     }
 // 在此处补充你的代码
     Complex & operator=(string s) {
         int position = s.find("+", 0);
         string firstPart = s.substr(0, position);
         string secondPart = s.substr(position+1, s.length() - position - 2);
         r = atof(firstPart.c_str());
         i = atof(secondPart.c_str());
         return *this;
     }
 };
// My Array
//　以下は私の作成部分。
class Array{
public:
    Complex *cmp;
    Array(int n){
        cmp = new Complex[n];
    }
    Complex &operator[](int n){
        return cmp[n];
    }
};
///////////////////////

int main() {
    //编程题＃1 编程作业—运算符重载
     Complex a;
     a = "3+4i"; a.Print();
     a = "5+6i"; a.Print();
    
     //////////////////////////////
     ///MyArray;
     string data[] = {"1+2i","3+4i","5+6i","7+8i","9+10i"};
     Array arr(5);
     for(int i = 0; i < 5; i++){
         arr[i] = data[i];
     }
     for(int i = 0; i < 5; i++){
         arr[i].Print();
     }
     return 0;
 }
