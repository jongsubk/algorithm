import java.io.*;

public class quick_sort {

  public static void main(String[] args) {

    int arr[] = { 3,2,1,4,5,9,8,7,6 };
    printArray(arr);
  }

  private static void printArray(int[] arr) {
    for( int i=0; i<arr.length; i++) {
      System.out.print(arr[i]+ " ");
    }
  }

  private static void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }



}
