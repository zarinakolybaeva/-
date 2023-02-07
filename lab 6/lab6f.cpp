#include <iostream>
#include <iomanip>
using namespace std;
double toNorm(string grade){
    if(grade == "A+") return 4.0;
    if(grade == "A") return 3.75;
    if(grade == "B+") return 3.50;
    if(grade == "B") return 3.00;
    if(grade == "C+") return 2.50;
    if(grade == "C") return 2.00;
    if(grade == "D+") return 1.50;
    if(grade == "D") return 1.00;
    return 0;
}

double getGPA(int n){
    double sum1 = 0, sum2 = 0;
    for(int i = 0; i < n ; i++){
        string s; int c; cin >> s >> c;
        sum1 += (toNorm(s) * c);
        sum2 += c;
    }
    return sum1/sum2;
}

class Student{
    public:
    string name, surname;
    double gpa;
    Student(string name, string surname, double gpa){
        this->name = name;
        this->surname = surname;
        this->gpa = gpa;
    }
    Student(){
        name = surname = gpa = NULL;
    }
    void print(){
        cout << surname << " " << name << " " << gpa << endl;
    }
};

bool cmp(Student s1, Student s2){
    if(s1.gpa!=s2.gpa){
        return s1.gpa < s2.gpa;
    }
    if(s1.surname != s2.surname){
        return s1.surname < s2.surname;
    }
    return s1.name < s2.name;
}

void heapify(Student arr[], int size, int index){
    int l = index*2 + 1;
    int r = index*2 + 2;
    int min = index;
    if(l < size && cmp(arr[min], arr[l])) min = l;
    if(r < size && cmp(arr[min], arr[r])) min = r;
    if(min != index){
        swap(arr[min], arr[index]);
        heapify(arr,size, min);
    }
}

void heapSort(Student arr[], int size){
    for(int i = size/2; i >= 0 ; i--){
        heapify(arr, size, i);
    }
    for(int i = size-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    int n; cin >> n;
    Student stu[n];
    for(int i = 0; i < n; i++){
        string name, surname; int m; cin >> surname >> name >> m;
        double gpa = getGPA(m);
        stu[i] = Student(name, surname, gpa);
    }
    heapSort(stu,n);
    cout << fixed << setprecision(3);
    for(int i = 0 ; i < n ;i++){
        stu[i].print();
    }


    return 0;
}