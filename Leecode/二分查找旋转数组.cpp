#include<vector>
#include<iostream>

using namespace std;


//如果左指针小于右指针，证明数组已经完全旋转，返回第一个元素即可，如果左指针大于右指针》》
//左指针大于中间值，那么最小值就一定在左指针和中间值之间
//左指针小于中间值，那么最小值就一定在右指针和中间值之间
//每次更新都去检查mid左右两侧是否都比它大，如果是，就输出

int main() {
    vector<int> nums = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int left = 0;
    int right = nums.size() - 1;
    int mid = left + (right - left) / 2;


    if (nums.size() >= 3) {
        if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
            return nums[mid];
        }
    }

    //完全旋转的情况
    if (nums[left] < nums[right]) {
        return nums[left];
        cout << nums[left];
    }

    //正常情况
    while (left <= right) {
        if (nums[left] > nums[mid]) {
            right = mid ;
        }
        else if(nums[left] < nums[mid]) {
            left = mid ;
        }
        else {
            if (nums[left] > nums[right]) {
                cout << nums[right];
                return nums[right];
            }
            else {
                cout << nums[left];
                return nums[left];
            }
        }
        mid = left + (right - left) / 2;
        //由于互不相同，不在考虑等于的逻辑
        if (nums[mid] <= nums[mid - 1] && nums[mid] <= nums[mid + 1]) {
            cout << nums[mid];
            return nums[mid];
           
        }
    }
    return 0;
}

