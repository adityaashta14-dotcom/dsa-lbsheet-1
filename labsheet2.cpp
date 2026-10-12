
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

#include <iostream>
using namespace std;
int main() {
    int a[]={10,20,30,40,50}, key=40;
    int l=0,r=4;
    while(l<=r) {
        int m=(l+r)/2;
        if(a[m]==key) {
            cout<<"Found at position "<<m+1;
            return 0;
        }
        if(a[m]<key) l=m+1;
        else r=m-1;
    }
    cout<<"Not found";
}

#include <iostream>
using namespace std;
int main() {
    int a[]={10,20,30,40,50}, key=30;
    for(int i=0;i<5;i++)
        if(a[i]==key) cout<<"Linear: "<<i+1<<endl;

    int l=0,r=4;
    while(l<=r) {
        int m=(l+r)/2;
        if(a[m]==key) {
            cout<<"Binary: "<<m+1;
            break;
        }
        if(a[m]<key) l=m+1;
        else r=m-1;
    }
}

#include <iostream>
using namespace std;
int main() {
    int a[]={5,2,4,1}, n=4;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        for(int k=0;k<n;k++) cout<<a[k]<<" ";
        cout<<endl;
    }
}

#include <iostream>
using namespace std;
int main() {
    int a[]={5,2,4,1}, n=4;
    for(int i=1;i<n;i++) {
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key) {
            a[j+1]=a[j]; j--;
        }
        a[j+1]=key;
    }
    for(int x:a) cout<<x<<" ";
}

#include <iostream>
using namespace std;
int main() {
    int a[]={5,2,4,1}, n=4;
    for(int i=0;i<n-1;i++) {
        int m=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[m]) m=j;
        cout<<"Min: "<<a[m]<<endl;
        swap(a[i],a[m]);
    }
    for(int x:a) cout<<x<<" ";
}

#include <iostream>
using namespace std;

void merge(int a[],int l,int m,int r) {
    int t[100],i=l,j=m+1,k=0;
    while(i<=m && j<=r)
        t[k++]=(a[i]<a[j])?a[i++]:a[j++];
    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++) a[i]=t[k++];
}
void sort(int a[],int l,int r) {
    if(l<r) {
        int m=(l+r)/2;
        sort(a,l,m); sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main() {
    int a[]={5,2,4,1},n=4;
    sort(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}

#include <iostream>
using namespace std;

int part(int a[],int l,int h) {
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[h]);
    return i+1;
}
void quick(int a[],int l,int h) {
    if(l<h) {
        int p=part(a,l,h);
        quick(a,l,p-1);
        quick(a,p+1,h);
    }
}
int main() {
    int a[]={5,2,4,1},n=4;
    quick(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}

int part(int a[],int l,int h) {
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)
        if(a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[h]);
    for(int k=0;k<4;k++) cout<<a[k]<<" ";
    cout<<endl;
    return i+1;
}

#include <iostream>
using namespace std;
int main() {
    int a[]={10,20,30,40,50},key,ch,pos=-1;
    cout<<"1.Linear  2.Binary: ";
    cin>>ch;
    cout<<"Enter key: "; cin>>key;

    if(ch==1) {
        for(int i=0;i<5;i++)
            if(a[i]==key) {pos=i;break;}
    } else if(ch==2) {
        int l=0,r=4;
        while(l<=r) {
            int m=(l+r)/2;
            if(a[m]==key){pos=m;break;}
            if(a[m]<key) l=m+1;
            else r=m-1;
        }
    }
    if(pos!=-1) cout<<"Position: "<<pos+1;
    else cout<<"Not found";
}
#include <iostream>
using namespace std;
int main() {
    int a[]={5,2,4,1},n=4,ch;
    cout<<"1.Bubble 2.Insertion 3.Selection: ";
    cin>>ch;

    if(ch==1)
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-i-1;j++)
                if(a[j]>a[j+1]) swap(a[j],a[j+1]);

    if(ch==2)
        for(int i=1;i<n;i++) {
            int k=a[i],j=i-1;
            while(j>=0 && a[j]>k)
                a[j+1]=a[j--];
            a[j+1]=k;
        }

    if(ch==3)
        for(int i=0;i<n-1;i++) {
            int m=i;
            for(int j=i+1;j<n;j++)
                if(a[j]<a[m]) m=j;
            swap(a[i],a[m]);
        }

    for(int x:a) cout<<x<<" ";
}

int main() {
    int a[]={5,2,4,1},n=4,key=4;
    sort(a,0,n-1);

    int l=0,r=n-1;
    while(l<=r) {
        int m=(l+r)/2;
        if(a[m]==key) {
            cout<<"Found at "<<m+1;
            return 0;
        }
        if(a[m]<key) l=m+1;
        else r=m-1;
    }
    cout<<"Not found";
}

#include <iostream>
using namespace std;
int main() {
    int a[]={5,2,4,1},n=4,c1=0,c2=0;
    int b[]={5,2,4,1};

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++) {
            c1++;
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++) {
            c2++;
            if(b[i]>b[j]) swap(b[i],b[j]);
        }

    cout<<"Bubble: "<<c1<<endl;
    cout<<"Selection-style: "<<c2;
}

#include <iostream>
using namespace std;
int main() {
    cout<<"Bubble: Best O(n), Average/Worst O(n^2)\n";
    cout<<"Insertion: Best O(n), Average/Worst O(n^2)\n";
    cout<<"Selection: Best/Average/Worst O(n^2)\n";
}