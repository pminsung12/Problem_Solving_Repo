#include <iostream>
using namespace std;

void swap(int &ref1, int &ref2){
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(){
    int size, num;
    cin>>size>>num;

    int *a = new int[size+1];
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    int count=0;
    while(size!=1){
        int max=0;
        for(int i=0;i<size;i++){
            if (a[i]>max) max=a[i];
        }
        for(int i=0;i<size;i++){
            if (a[i]==max){
                if(a[i]>a[size-1]){
                    swap(a[i], a[size-1]);
                    count++;
                    if(count==num){
                        cout<<a[i]<<" "<<a[size-1]<<endl;
                        return 0;
                    }
                }
                size--;
                
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}