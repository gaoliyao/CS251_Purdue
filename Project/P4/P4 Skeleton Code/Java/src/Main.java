import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * This is your Main program. This File will be run all operations, based on the input different function will be called.
 *
 * Complete the given and add necessary functions as per your requirement.
 */

public class Main {
    public static void RyhmeOrder(Scanner in, PrintWriter out){
        //use in and out for file input output
        //use your implemented Quick Sort for solving RhymeOrder Operation
    }

    public static void SuffixShare(Scanner in, PrintWriter out, int k){
        //use in and out for file input output
        //use your implemented QuickSort for solving Suffix Operation
    }


    public static void main(String[] args) {
        if(args.length!=2){
            System.out.println("ERROR: Not enough Parameters");
            System.exit(0);
        }
        Scanner in=null;
        PrintWriter out=null;
        try {
            in = new Scanner(new File(args[0]));
            out= new PrintWriter(new File(args[1]));
        }
        catch (Exception e){
            e.printStackTrace();
            System.exit(0);
        }

        int PartNo=in.nextInt();

        if(PartNo==1){
            //Part 1: Word Sorting
            int OperationNo=in.nextInt();
            if(OperationNo==1){
                //Operation: Rhyme Word Sorting Order
                RyhmeOrder(in,out);
            }
            else if (OperationNo==2){
                //Operation: Rhyme Word Sorting Order
                int k=in.nextInt();
                
                SuffixShare(in,out, k)
            }
            else{
                System.out.println("Invalid Input");
                System.exit(0);
            }
            
        }
       
        else if(PartNo==2){
            //Problem 2: B-Tree Problem
            
        }
        
        else{
            System.out.println("Invalid Input");
            System.exit(0);
        }

        in.close();
        out.close();
    }
}