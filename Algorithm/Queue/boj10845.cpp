// 큐 직접 구현

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

inline void Quick_IO(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class queue{
private:
    int* head;
    int* tail;
    int* arr;
public:
    queue(int n){
        arr = new int[n+1];
        head = arr;
        tail = arr;
    }
    int pop(){
        return *(head++);
    }
    void push(int x){
        *(tail++) = x;
    }
    bool empty(){
        if(head==tail)
            return true;
        else return false;
    }
    int front(){
        return *head;
    }
    int back(){
        return *(tail-1);
    }
    int size(){
        return tail - head;
    }
};

int main(){
    Quick_IO();
    int N;
    cin>>N;
    queue stck(N);
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
            }else if(q=="front"){
                if(stck.empty()){
                    cout<<-1;
                }else{
                    cout<< stck.front();
                }
            }else if(q=="back"){
                if(stck.empty()){
                    cout<<-1;
                }else{
                    cout<<stck.back();
                }
            }
            cout<<"\n";
        }
    }

    return 0;
}