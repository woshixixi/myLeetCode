#include <iostream>
#include <vector>
using namespace std;


    int reverse(int x) {
        long long result = 0;
        while(x) {
            result = x % 10 + result *10;
            x = x / 10;
        }
//        if(result < INT_MIN || result > INT_MAX){
//            return 0;
//        }else{
//            return result;
//        }
        return result;
    }
int main() {
    int a;
    while(cin>>a){
        int b = reverse(a);
        cout<<b<<endl;
    }
    return 0;
}