import java.util.*;
import java.io.*;

class ProcessNode {
    public int value;
    public int mod;

    public void compute(int choice, ProcessNode[] process, int a, int b) {
        if(choice == 1) {
            int first = process[a].value;
            int second = process[b].value;
            process[a].value = Math.min(first, second);
            process[b].value = Math.max(first, second);
        }
        if(choice==2) {
            int first = process[a].value;
            int second = process[b].value;
            process[a].value = Math.max(first, second);
            process[b].value = Math.min(first, second);
        }
    }

    public void compute(int choice, ProcessNode[] process, int a, int b, int c) {
        if(choice==1) {
            int first = process[a].value;
            int second = process[b].value;
            int third = process[c].value;
            int sum = first + second + third;
            process[a].value = Math.min(Math.min(first, second), third);
            process[c].value = Math.max(Math.max(first, second), third);
            process[b].value = sum - (process[a].value + process[c].value);
        }
        if(choice==2) {
            int first = process[a].value;
            int second = process[b].value;
            int third = process[c].value;
            int sum = first + second + third;
            process[a].value = Math.max(Math.max(first, second), third);
            process[c].value = Math.min(Math.min(first, second), third);
            process[b].value = sum - (process[a].value + process[c].value);
        }
        
    }

    public void printProcesses(ProcessNode[] process, int num) {
        for(int i=0;i<num;i++) {
            System.out.print(process[i].value + "  ");
        }
        System.out.println();
    }
}

public class AlternateAlgorithm {
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter number of elements : ");
        int num = sc.nextInt();
        ProcessNode process[] = new ProcessNode[num];

        System.out.print("Enter array elements : ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String  lines = br.readLine();    
        String[] strs = lines.trim().split("\\s+");
                
        System.out.print("1.) Ascending     2.) Descending    (1/2) : ");
        int choice = sc.nextInt();

        for (int i = 0; i < strs.length; i++) {
            process[i] = new ProcessNode();
            process[i].value = Integer.parseInt(strs[i]);
            process[i].mod = i%3;
        }
        ProcessNode pro = new ProcessNode();

        for(int i=1;i<num;i++) {
            for(int j=0;j<num;j++) {
                if(process[i].mod == j%3) {
                    // System.out.print(process[j].value + " ");
                    if(j==0) {
                        pro.compute(choice, process, j, j+1);
                    }
                    else if(j==num-1) {
                        pro.compute(choice, process, j-1, j);
                    }
                    else {
                        pro.compute(choice, process, j-1, j, j+1);
                    }
                }   
            }
            // System.out.println(); 
            System.out.print("Round " + i + ": ");
            pro.printProcesses(process, num);
        }
        if(choice==1)
            System.out.print("\nArray sorted in ascending order is:  ");
        if(choice==2)
            System.out.print("\nArray sorted in descending order is:  ");
        pro.printProcesses(process, num);

        sc.close();
    }   
}
