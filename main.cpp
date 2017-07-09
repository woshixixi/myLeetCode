#include <iostream>
#include <vector>
using namespace std;




int main() {
    vector<int>nums ={3,2,4};
    int target = 6;
    vector<int> rs=twoSum(nums,target);
    cout <<"["<<rs[0]<<","<<rs[1]<<"]";
    return 0;
}