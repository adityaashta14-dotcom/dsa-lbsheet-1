
#include <iostream>
using namespace std;
int main() {
    int a[]={10,20,30,40}, key=30;
    for(int i=0;i<4;i++)
        if(a[i]==key) {
            cout<<"Found at position "<<i+1;
            return 0;
        }
    cout<<"Not found";
}