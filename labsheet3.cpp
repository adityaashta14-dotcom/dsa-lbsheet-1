
#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,4,1},n=4;
    cout<<"Before: ";
    for(int x:a) cout<<x<<" ";
    cout<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        for(int x:a) cout<<x<<" ";
        cout<<endl;
    }
}

#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,4,1},n=4;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
    for(int x:a) cout<<x<<" ";
}

#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,4,1},n=4;
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j]; j--;
        }
        a[j+1]=key;
        for(int x:a) cout<<x<<" ";
        cout<<endl;
    }
}

#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,4,1},n=4;
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[m]) m=j;
        cout<<"Minimum: "<<a[m]<<endl;
        swap(a[i],a[m]);
    }
    for(int x:a) cout<<x<<" ";
}

#include <iostream>
using namespace std;
void merge(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0;
    while(i<=m && j<=r)
        t[k++]=(a[i]<a[j])?a[i++]:a[j++];
    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++) a[i]=t[k++];
}
void ms(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        ms(a,l,m); ms(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int a[]={5,3,4,1},n=4;
    ms(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}

#include <iostream>
using namespace std;
int part(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[h]);
    return i+1;
}
void qs(int a[],int l,int h){
    if(l<h){
        int p=part(a,l,h);
        qs(a,l,p-1); qs(a,p+1,h);
    }
}
int main(){
    int a[]={5,3,4,1};
    qs(a,0,3);
    for(int x:a) cout<<x<<" ";
}

int part(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[h]);
    cout<<"Partition: ";
    for(int k=0;k<4;k++) cout<<a[k]<<" ";
    cout<<endl;
    return i+1;
}

#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,4,1},n=4,ch;
    cout<<"1.Bubble 2.Insertion 3.Selection\n";
    cout<<"4.Merge 5.Quick\n";
    cin>>ch;
    if(ch==1)
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-i-1;j++)
                if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    if(ch==2)
        for(int i=1;i<n;i++){
            int k=a[i],j=i-1;
            while(j>=0&&a[j]>k) a[j+1]=a[j--];
            a[j+1]=k;
        }
    if(ch==3)
        for(int i=0;i<n-1;i++){
            int m=i;
            for(int j=i+1;j<n;j++)
                if(a[j]<a[m]) m=j;
            swap(a[i],a[m]);
        }
    if(ch==4){
        // Add merge-sort functions from Q5
        cout<<"Use Merge Sort code from Q5\n";
        return 0;
    }
    if(ch==5){
        // Add quick-sort functions from Q6
        cout<<"Use Quick Sort code from Q6\n";
        return 0;
    }
    for(int x:a) cout<<x<<" ";
}

#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,4,1},n=4;
    int b[]={5,3,4,1},c[]={5,3,4,1};
    int x=0,y=0,z=0;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            x++;
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    for(int i=1;i<n;i++){
        int k=b[i],j=i-1;
        while(j>=0){y++; if(b[j]<=k)break;
            b[j+1]=b[j--];}
        b[j+1]=k;
    }
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            z++; if(c[j]<c[m])m=j;
        }
        swap(c[i],c[m]);
    }
    cout<<"Bubble: "<<x<<endl;
    cout<<"Insertion: "<<y<<endl;
    cout<<"Selection: "<<z;
}

#include <iostream>
using namespace std;
int main(){
    int ch;
    cout<<"1.Bubble Sort\n2.Insertion Sort\n";
    cout<<"3.Selection Sort\n4.Merge Sort\n5.Quick Sort\n";
    cout<<"Enter choice: ";
    cin>>ch;
    cout<<"Selected algorithm: "<<ch;
    // Call the corresponding sorting function
}

#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,4,1},n=4;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    cout<<"Ascending: ";
    for(int x:a) cout<<x<<" ";
    cout<<"\nDescending: ";
    for(int i=n-1;i>=0;i--) cout<<a[i]<<" ";
}

#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,4,1},n=4,c=0;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            c++;
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    cout<<"Bubble comparisons: "<<c<<endl;

    int b[]={5,3,4,1},d=0;
    for(int i=1;i<n;i++){
        int k=b[i],j=i-1;
        while(j>=0){d++;if(b[j]<=k)break;
            b[j+1]=b[j--];}
        b[j+1]=k;
    }
    cout<<"Insertion comparisons: "<<d<<endl;

    int e[]={5,3,4,1},f=0;
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            f++;
            if(e[j]<e[m])m=j;
        }
        swap(e[i],e[m]);
    }
    cout<<"Selection comparisons: "<<f;
}

#include <iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4},n=4,c=0;
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            c++;
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
    cout<<"Bubble comparisons: "<<c<<endl;

    c=0;
    for(int i=1;i<n;i++){
        int k=a[i],j=i-1;
        while(j>=0 && (c++,a[j]>k)){
            a[j+1]=a[j--];
        }
        a[j+1]=k;
    }
    cout<<"Insertion comparisons: "<<c;
}

#include <iostream>
using namespace std;

int part(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[h]);
    return i+1;
}
void qs(int a[],int l,int h){
    if(l<h){
        int p=part(a,l,h);
        qs(a,l,p-1);
        qs(a,p+1,h);
    }
}
int main(){
    int a[]={1,2,3,4,5};
    int b[]={5,4,3,2,1};
    int c[]={3,1,5,2,4};

    qs(a,0,4);
    qs(b,0,4);
    qs(c,0,4);

    cout<<"Sorted array: ";
    for(int x:a) cout<<x<<" ";
    cout<<"\nReverse array: ";
    for(int x:b) cout<<x<<" ";
    cout<<"\nRandom array: ";
    for(int x:c) cout<<x<<" ";
}