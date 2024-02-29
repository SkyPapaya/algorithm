package example.binarySearch;

public class BinarySearch {

    public static int search(int[] nums, int target) {
        //定义用于搜寻的左右指针
        int left = 0;
        int right = nums.length - 1;
        //向下取整并防止整型溢出
        int mid = left + (right - left) / 2;
        while (left <= right) {
            //成功搜索
            if (nums[mid] == target) {
                return left;
            }
            //目标位于中间值之前
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;

        }
        return -1;

    }


}
