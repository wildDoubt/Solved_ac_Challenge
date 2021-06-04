// 스택 직접 구현

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class stack{
private:
    int* head;
    int* tail;
    int* arr;
public:
    stack(int n){
        arr = new int[n+1];
        head = arr;
        tail = arr+1;
    }
    int pop(){
        return *(tail--);
    }
    void push(int x){
        *(++tail) = x;
    }
    bool empty(){
        if(head==tail-1)
            return true;
        else return false;
    }
    int top(){
        return *tail;
    }
    int size(){
        return tail - head-1;
    }
};

int main(){
    Quick_IO();
    int N;
    cin>>N;
    stack stck(N);
    while(N--){
        string q;
        cin>>q;
        if(cin.peek()==' '){
            int a;
            cin>>a;
            stck.push(a);
        }else{
            if(q=="pop"){
                if(stck.empty()){
                    cout<<-1;
                }else{
                    cout<<stck.pop();
                }
            }else if(q=="size"){
                cout<<stck.size();
            }else if(q=="empty"){
                cout<<stck.empty();
            }else if(q=="top"){
                if(stck.empty()){
                    cout<<-1;
                }else{
                    cout<<stck.top();
                }
            }
            cout<<"\n";
        }
    }

    return 0;
}