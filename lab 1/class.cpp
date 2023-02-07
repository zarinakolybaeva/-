#include<iostream>
#include<list>
using namespace std;
class youtube {
public:
string name;
string ownname;
int cnt;
list<string>pub;
};
int main (){
 youtube channel;
 channel.name="codebeauty";
 channel.ownname="zarina";
 channel.cnt=1000;
 channel.pub={"sdfs","dzxc"};
 cout<<channel.name<<endl;
}