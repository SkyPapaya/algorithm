import example.binarySearch.BinarySearch;
import example.binarySearch.FindInsertPosition;
import example.binarySearch.FindTheFirstandTheLastPosition;

public class Main {

    public static void main(String[] args) {
        int[] nums = {5, 7, 7, 8, 8, 10};
        int target = 8;
        FindTheFirstandTheLastPosition findTheFirstandTheLastPosition = new FindTheFirstandTheLastPosition();
        int result[] = findTheFirstandTheLastPosition.findFirstAndLastPosition(target, nums);
        System.out.println(result[0] + "," + result[1]);
    }
}
