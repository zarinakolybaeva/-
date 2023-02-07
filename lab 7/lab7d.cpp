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

void merge(Student a[], int l, int m, int r){
    int sub1 = m - l + 1;
    int sub2 = r - m;
    Student * left = new Student[sub1];
    Student * rigth = new Student[sub2];
    for(int i = 0; i < sub1; i++){
        left[i] = a[l+i];
    }
    for(int i = 0; i < sub2; i++){
        rigth[i] = a[m+i+1];
    }
    int leftI = 0, rigthI = 0, mergeI = l;
    while(leftI < sub1 && rigthI < sub2){
        if(cmp(left[leftI], rigth[rigthI])){
            a[mergeI] = left[leftI];
            leftI++;
        }
        else{
            a[mergeI] = rigth[rigthI];
            rigthI++;
        }
        mergeI++;
    }
    while(leftI < sub1){
        a[mergeI] = left[leftI];
        leftI++;
        mergeI++;
    }
    while(rigthI < sub2){
        a[mergeI] = rigth[rigthI];
        rigthI++;
        mergeI++;
    }
    delete[] left; delete[] rigth;
}

void mergeSort(Student arr[], int l, int r){
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(arr, l,mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main() {
    int n; cin >> n;
    Student stu[n];
    for(int i = 0; i < n; i++){
        string name, surname; int m; cin >> surname >> name >> m;
        double gpa = getGPA(m);
        stu[i] = Student(name, surname, gpa);
    }
    mergeSort(stu,0, n-1);
    cout << fixed << setprecision(3);
    for(int i = 0 ; i < n ;i++){
        stu[i].print();
    }
    return 0;
}