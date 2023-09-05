import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Array<T> {
    private T[] data;

    public Array(T[] data) {
        this.data = data;
    }

    public Array() {

    }

    /**
     * @param location the location of the file
     * @return
     * @throws IOException
     */
    //transform text to string array
    public T[] getText(String location) throws IOException {


        String file = location;
        BufferedReader reader = new BufferedReader(new FileReader(file));
        String currentLine = reader.readLine();
        T[] textData = (T[]) currentLine.split(" ");
        reader.close();
        return textData;

    }

    public void setData(T[] data) {
        this.data = data;
    }



    public void adjustHeap(Integer[] arr, int target, int number) {
        //这三个值均是下标
        int largest = target;
        int left = target * 2 + 1;
        int right = target * 2 + 2;
        if (left <= number && right <= number) {


            //没有进行到堆的底部并且左孩子大于父节点
            if (left < number && arr[target] < arr[left]) {
                largest = left;
            }
            //没有进行到堆的底部并且右孩子大于父节点
            if (right < number && arr[largest] < arr[right]) {
                largest = right;
            }
            //如果堆顶坐标应该被刷新，就交换元素
            if (largest != target) {
                int temp = arr[target];
                arr[target] = arr[largest];
                arr[largest] = temp;
                //largest的值如果被刷新，那么需要继续维护接下来的堆
                adjustHeap(arr, largest, number);
            }
        }
    }

    public void heapSort(Integer[] arr) {

        int length = arr.length;
        //creat heap

        for (int i = length / 2 - 1; i > 0; i--) {
            adjustHeap(arr, i, length);
        }

        for (int i = length - 1; i > 0; i--) {
            //swap the largest one and the smallest one
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            //start from the first one everytime and excepting the largest one
            adjustHeap(arr, 0, i);
        }
    }

    public void adjustHeapString(String[] arr ,int target , int number){
        int largest = target;
        int left = target * 2 + 1;
        int right = target * 2 + 2;
        if (left <= number && right <= number) {


            //没有进行到堆的底部并且左孩子大于父节点
            if (left < number && arr[target].compareTo(arr[left]) < 0) {
                largest = left;
            }
            //没有进行到堆的底部并且右孩子大于父节点
            if (right < number && arr[largest].compareTo(arr[right]) > 0) {
                largest = right;
            }
            //如果堆顶坐标应该被刷新，就交换元素
            if (largest != target) {
                String temp = arr[target];
                arr[target] = arr[largest];
                arr[largest] = temp;
                //largest的值如果被刷新，那么需要继续维护接下来的堆
                adjustHeapString(arr, largest, number);
            }
        }
    }
    public void heapSortString(String[] arr){
        int length = arr.length;
        //creat heap

        for (int i = length / 2 - 1; i > 0; i--) {
            adjustHeapString(arr, i, length);
        }

        for (int i = length - 1; i > 0; i--) {
            //swap the largest one and the smallest one
            String temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            //start from the first one everytime and excepting the largest one
            adjustHeapString(arr, 0, i);
        }
    }


    public void stringSort(String location) throws IOException {
        T[] stArray = getText(location);
        int length = stArray.length;
        //to save strings
        Map<Integer, String> stMap = new HashMap<Integer, String>();
        //input data as key and value
        for (int i = 0; i < length; i++) {
            stMap.put(i, (String) stArray[i]);
        }
        //用字符串大小来刷新key
        int largest = length - 1;

        ArrayList<Integer> keys = new ArrayList<Integer>();
        for (int i = 0; i < length - 1; i++) {
            //前一个比后一个大，键插入到末尾反之插入到首部
            if ((i + 1) == stArray.length) {
                break;
            }
            if (stMap.get(i).compareTo(stMap.get(i + 1)) < 0) {
                keys.add(i + 1);
            } else {
                keys.add(0, i);
            }
        }
        for (int i = 0; i < keys.size(); i++) {
            //如果最后一位大于任意一个下标为i的值，并且小于小标为i + 1 的值，那么就插入到它们中间，并将之后的值全部加1
            if (stMap.get(stMap.size() - 1).compareTo(stMap.get(i)) <= 0 && stMap.get(stMap.size() - 1).compareTo(stMap.get(i + 1)) > 0) {
                //将i+1和它之后的值向后移动并且值全部加1
                int capy = keys.size();
                keys.add(keys.get(capy - 1));
                for (int j = 0; j < capy + 1 - i; j++) {
                    keys.set(capy - 2 - j, keys.get(capy - 3 - j));
                    Integer m = Integer.sum(1, keys.get(capy - 2 - j));
                    keys.set(capy - 2 - j, m);
                }
            }
        }
        Integer[] myKeys = new Integer[keys.size()];
        for (int i = 0; i < keys.size(); i++) {
            myKeys[i] = keys.get(i);
        }
        //keys存的键值就代表了字符串的大小位置
        heapSort(myKeys);
        System.out.println(keys);
        for (Integer i : myKeys) {
            System.out.println(myKeys[i]);
        }
    }

}


