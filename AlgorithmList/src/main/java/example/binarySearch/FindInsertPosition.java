package example.binarySearch;

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

作者：liweiwei1419
链接：https://leetcode.cn/leetbook/read/learning-algorithms-with-leetcode/xsy6tj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
public class FindInsertPosition {

    //数组为无重复元素的升序数组，给定一个目标值，返回目标值应该插入在数组中的坐标位置
    public static int findPosition(int target, int[] nums) {

        int left = 0;
        int right = nums.length - 1;
        int mid = left + (right - left) / 2;
        //插入位置分别在首尾
        if (target < nums[left]) {
            return left;
        }
        //这里不能取目标值等于右端值，因为是非重复数组
        if (target > nums[right]) {
            return right + 1;
        }

        while (left < right) {
            //中间值比target小，搜索区间放在右边
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
            mid = left + (right - left) / 2;
        }

        return left;
    }
}
