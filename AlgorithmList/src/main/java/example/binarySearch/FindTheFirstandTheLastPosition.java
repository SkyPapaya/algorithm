package example.binarySearch;

/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
[5,7,7,7,8,8,8]
如果数组中不存在目标值 target，返回[-1, -1]。

你必须设计并实现时间复杂度为O(log n)的算法解决此问题。

作者：liweiwei1419
链接：https://leetcode.cn/leetbook/read/learning-algorithms-with-leetcode/xsc8ut/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
public class FindTheFirstandTheLastPosition {
    //数组中无这个元素
    public  int[] findFirstAndLastPosition(int target, int[] nums) {
        int result[] = {-1, -1};
        if (target > nums[nums.length - 1] || target < nums[0]) {
            return result;
        }

        result[0] = findFirstPosition(target, nums);
        result[1] = findLastPosition(target, nums);
        return result;
    }


    private int findFirstPosition(int target, int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int mid = left + (right - left) / 2;

        while (left < right) {
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                right = mid;
            } else {
                right = mid -1;
            }

            mid = left + (right - left) / 2;
        }
        if (nums[left] == target) {
            return left;
        }
        return -1;
    }

    int findLastPosition(int target, int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int mid = left + (right - left) / 2;

        while (left < right) {
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                left = mid;
            } else {
                right = mid -1;
            }

            mid = left + (right - left + 1) / 2;
        }
        if (nums[left] == target) {
            return left;
        }
        return -1;
    }

}
