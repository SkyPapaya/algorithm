#include<vector>
#include<iostream>

using namespace std;


//�����ָ��С����ָ�룬֤�������Ѿ���ȫ��ת�����ص�һ��Ԫ�ؼ��ɣ������ָ�������ָ�롷��
//��ָ������м�ֵ����ô��Сֵ��һ������ָ����м�ֵ֮��
//��ָ��С���м�ֵ����ô��Сֵ��һ������ָ����м�ֵ֮��
//ÿ�θ��¶�ȥ���mid���������Ƿ񶼱���������ǣ������

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

    //��ȫ��ת�����
    if (nums[left] < nums[right]) {
        return nums[left];
        cout << nums[left];
    }

    //�������
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
        //���ڻ�����ͬ�����ڿ��ǵ��ڵ��߼�
        if (nums[mid] <= nums[mid - 1] && nums[mid] <= nums[mid + 1]) {
            cout << nums[mid];
            return nums[mid];
           
        }
    }
    return 0;
}

