import java.io.*;
import java.util.*;

class Process {
    public int leftValue, rightValue;
    public int leftMarked, rightMarked, area;

    void printProcesses(int round, Process process[], int num) {
        System.out.print("Round " + round + " :  ");
        for(int i=0;i<num;i++) {
            String left="";
            String right="";
                if(process[i].leftMarked == 1) {
                    left = "*";
                }
                if(process[i].rightMarked == 1) {
                    right ="*";
                }
            if(i==0)
                System.out.print("[ " + process[i].rightValue + right + " (" + process[i].area + ") ]     ");
            else if(i==num-1)
                System.out.print("[ " + process[i].leftValue + left + " (" + process[i].area + ") ]     ");
            else
                System.out.print("[ " + process[i].leftValue + left + ", " + process[i].rightValue + right + " (" + process[i].area + ") ]     ");
        }
        System.out.println();
    }
    void printOutput(Process process[], int num, int choice) {
        if(choice==1)
            System.out.print("\nArray sorted in ascending order is:  ");
        if(choice==2)
            System.out.print("\nArray sorted in descending order is:  ");
            
        System.out.print(process[0].rightValue + " ");

        for(int i=1;i<num-1;i++) {   
            if(process[i].area == -1) {
                System.out.print(process[i].rightValue + " ");
            }
            if(process[i].area == 0 || process[i].area == 1) {
                System.out.print(process[i].leftValue + " ");
            }
        }
        System.out.println(process[num-1].leftValue + " \n");
    }
}

public class SasakiAlgorithm {

    Process process[] = new Process[100];
    public static void main(String args[]) throws IOException {

        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter number of elements : ");
        int num = sc.nextInt();
        
        Process nodes[] = new Process[num];
        System.out.print("Enter array elements : ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String  lines = br.readLine();
        String[] strs = lines.trim().split("\\s+");
        System.out.print("1.) Ascending     2.) Descending    (1/2) : ");
        int choice = sc.nextInt();

        for(int i=0;i<num;i++) {
            nodes[i] = new Process();
            nodes[i].leftValue = Integer.parseInt(strs[i]);
            nodes[i].rightValue = Integer.parseInt(strs[i]);
            if(i==0) {
                nodes[i].area = -1;
                nodes[i].rightMarked = 1;
            }
            else if(i==num-1) {
                nodes[i].area = 0;
                nodes[i].leftMarked = 1;
            }
            else {
                nodes[i].area = 0;
                nodes[i].leftMarked = 0;
                nodes[i].rightMarked = 0;
            }  
        }
        System.out.println();
        Process pro = new Process();
        if(choice == 1) {
            startAscendingAlgorithm(nodes, num, pro);
        }
        if(choice == 2) {
            startDescendingAlgorithm(nodes, num, pro);
        }
        pro.printOutput(nodes, num, choice);

        sc.close();
    }

    public static void startAscendingAlgorithm(Process[] process, int num, Process pro) {
        
        for(int round = 0; round < num-1; round++) {
            pro.printProcesses(round, process, num);
            for(int i=0; i<num-1; i++) {
                
                if(process[i].rightValue > process[i+1].leftValue) {
                    int temp = process[i].rightValue;
                    process[i].rightValue = process[i+1].leftValue;
                    process[i+1].leftValue = temp;

                    if(process[i].rightMarked==1) {
                        process[i+1].area = (process[i+1].area == -1 ? -1 : process[i+1].area - 1) ;
                    }
                    if(process[i+1].leftMarked == 1){
                        process[i+1].area = (process[i+1].area == 1 ? 1 : process[i+1].area + 1);
                    }

                    int mark = process[i].rightMarked;
                    process[i].rightMarked = process[i+1].leftMarked;
                    process[i+1].leftMarked = mark;
                        
                }
                /* Swapping Values in a single process */
                if(i!=0 && process[i].leftValue > process[i].rightValue) {
                    int temp = process[i].leftValue;
                    process[i].leftValue = process[i].rightValue;
                    process[i].rightValue = temp;
                    
                    int mark = process[i].rightMarked;
                    process[i].rightMarked = process[i].leftMarked;
                    process[i].leftMarked = mark;
                    
                }
                
            }
            
        }
    }

    public static void startDescendingAlgorithm(Process[] process, int num, Process pro) {
        
        for(int round = 0; round < num; round++) {
            pro.printProcesses(round, process, num);
            for(int i=0; i<num-1; i++) {
                
                if(process[i].rightValue < process[i+1].leftValue) {
                    int temp = process[i].rightValue;
                    process[i].rightValue = process[i+1].leftValue;
                    process[i+1].leftValue = temp;

                    if(process[i].rightMarked==1) {
                        process[i+1].area = (process[i+1].area == -1 ? -1 : process[i+1].area - 1) ;
                    }
                    if(process[i+1].leftMarked == 1){
                        process[i+1].area = (process[i+1].area == 1 ? 1 : process[i+1].area + 1);
                    }

                    int mark = process[i].rightMarked;
                    process[i].rightMarked = process[i+1].leftMarked;
                    process[i+1].leftMarked = mark;
                        
                }
                /* Swapping Values in a single process */
                if(i!=0 && process[i].leftValue < process[i].rightValue) {
                    int temp = process[i].leftValue;
                    process[i].leftValue = process[i].rightValue;
                    process[i].rightValue = temp;
                    
                    int mark = process[i].rightMarked;
                    process[i].rightMarked = process[i].leftMarked;
                    process[i].leftMarked = mark;
                    
                }
                
            }
        }
    }
}

