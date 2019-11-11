
public class quick_sort {

  public static void main(String[] args) {

    int arr[] = { 3, 5, 2, 1, 4 };

    quickSort(arr, 0, arr.length-1);

    printArray(arr);
  }

  private static void quickSort(int[] arr, int s, int e) {
    
    if( s >= e ) { return; }

    int left = s;
    int right = e;
    int pivot = arr[(s+e)/2];

    while( s < e ) {
      
      while( arr[s] < pivot ) { s++; }
      while( arr[e] > pivot ) { e--; }

      swap(arr, s, e);
    }

    //s == e == (index of pivot)
    quickSort(arr, left, s-1);
    quickSort(arr, s+1, right);
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
