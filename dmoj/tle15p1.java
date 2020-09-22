import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner (System.in);
    int a = in.nextInt(), b=in.nextInt();
    int [] arr = new int [a];
    String [] s = new String [a];
    in.nextLine();
    for(int i = 0;i<a;i++){
      s[i]=in.nextLine();
    }
    for(int i = 0;i<a;i++){
      arr[i]=0;
    }
    //in.nextLine();
    for(int i = 0;i<b;i++){
      for(int j = 0;j<a;j++){
        int k = in.nextInt();
        arr[j]+=k;
      }
    }
    TreeMap<Integer, String> tmap = 
    new TreeMap<Integer, String>(Collections.reverseOrder());
    for(int i = 0;i<a;i++){
      tmap.put(arr[i],s[i]);
    }
    Arrays.sort(arr);
    reverse(arr, arr.length);
    for(int i = 0;i<a;i++){
      System.out.println((i+3)+". "+tmap.get(arr[i]));
    } 
  }
  static int [] reverse(int a[], int n) 
    { 
        //int[] b = new int[n]; 
        //int j = n; 
        for (int i = 0; i < n/2; i++) { 
            int temp = a[i]; 
            a[i] = a[n-i-1];//j = j - 1; 
            a[n-i-1]=temp;
        } 
        return a;
    }
}