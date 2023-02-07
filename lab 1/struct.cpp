#include<iostream>
using namespace std;
    struct Student{
    // string name;
    // int age;    
    // double gpa;
    Student(string name,int age,double gpa){
        this -> name = name;
        this -> age = age;
        this -> gpa = gpa;
}
    
};
    int main(){
        // Student a;
        // a.name="Kirill";
        // a.age=21;
        // a.age=1.5;
     Student a ("Kirill",21,1.5);
     cout<<a.name;
    }
