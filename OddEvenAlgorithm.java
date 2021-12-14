import java.util.*;
import java.io.*;

public class OddEvenAlgorithm {
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter number of elements : ");
        int num = sc.nextInt();
        int threads[] = new int[num];

        System.out.print("Enter array elements : ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String  lines = br.readLine();    
        String[] strs = lines.trim().split("\\s+");
                
        System.out.print("1.) Ascending     2.) Descending    (1/2) : ");
        int choice = sc.nextInt();

        for (int i = 0; i < strs.length; i++) {
            threads[i] = Integer.parseInt(strs[i]);
        }

        if(choice==1) {
            boolean sorted = false;
            while (!sorted) {
                sorted = true;
                for (int i = 0; i < threads.length - 1; i += 2) {
                    if (threads[i] > threads[i + 1]) {
                        int temp = threads[i];
                        threads[i] = threads[i + 1];
                        threads[i + 1] = temp;
                        sorted = false;
                    }
                }
                for (int i = 1; i < threads.length - 1; i += 2) {
                    if (threads[i] > threads[i + 1]) {
                        int temp = threads[i];
                        threads[i] = threads[i + 1];
                        threads[i + 1] = temp;
                        sorted = false;
                    }
                }
            }
        }
        if(choice==2) {
            boolean sorted = false;
            while (!sorted) {
                sorted = true;
                for (int i = 0; i < threads.length - 1; i += 2) {
                    if (threads[i] < threads[i + 1]) {
                        int temp = threads[i];
                        threads[i] = threads[i + 1];
                        threads[i + 1] = temp;
                        sorted = false;
                    }
                }
                for (int i = 1; i < threads.length - 1; i += 2) {
                    if (threads[i] < threads[i + 1]) {
                        int temp = threads[i];
                        threads[i] = threads[i + 1];
                        threads[i + 1] = temp;
                        sorted = false;
                    }
                }
            }
        }
        
        if(choice==1)
            System.out.print("\nArray sorted in ascending order is:  ");
        if(choice==2)
            System.out.print("\nArray sorted in descending order is:  ");

        for(int i=0;i<num;i++) {
            System.out.print(threads[i] + " ");
        }

        sc.close();
    }
}
