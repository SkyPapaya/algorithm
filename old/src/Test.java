import org.w3c.dom.ranges.Range;

import java.io.IOException;
import java.util.Arrays;
import java.util.Random;

public class Test {


    //进行堆排序


    //create a random array
    static Integer[] randomInts() {
        Integer[] arr = new Integer[100];

        for (int i = 0; i < 100; i++) {
            arr[i] = (int) (Math.random() * 10);
        }
        return arr;
    }

    public static void main(String[] args) throws IOException {
        //test Integer

        //testing 100 random Integer
//        Integer[] arr = randomInts();
//        Array<Integer> array = new Array<>(arr);
//        array.heapSort(arr);
//        for (int j : arr) {
//            System.out.print(j + " ");
//        }


        Array array = new Array();
        String[] textArray = (String[]) array.getText("D://Code//Algorithm//old//text.txt/");
        String[] aa = Arrays.toString(textArray).replace("[", "").replace("]", "").split(",");
        array.setData(aa);
        array.heapSortString(aa);
        System.out.println("经过排序，按字母升序顺序为：");
        for (int i = 0; i < aa.length ; i++) {

            System.out.print(aa[i] + " ");
        }
        // array.stringSort("D://Code//Algorithm//heap sort//text.txt/");

        // System.out.println(Arrays.toString(textArray));


    }
}