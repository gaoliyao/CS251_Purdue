import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * This is your Main program. This File will be run to test all cases, based on the input different function will be called.
 *
 * Complete the given and add necessary functions as  per your requirement.
 */

public class Main {
    public static void StackChecking(Scanner in, PrintWriter out){
        //use in and out for file input output
        //use your implemented stack for solving problem 1
    }

    public static void WordSearch(Scanner in, PrintWriter out){
        //use in and out for file input output
        //use your implemented stack for solving problem 2
    }


    public static void CircularQueue(Scanner in, PrintWriter out){
        //use in and out for file input output
        //use your implemented stack for solving problem 3
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

        int ProblemNo=in.nextInt();

        if(ProblemNo==1){
            //Problem 1: Checking of your implemented stack
            StackChecking(in,out);
        }
        else if(ProblemNo==2){
            //Problem 2: Word searching probme
            WordSearch(in, out);
        }
        else if(ProblemNo==3){
            //Problem 3: Circular Dequeue Implementation checking
            CircularQueue(in, out);
        }
        else{
            System.out.println("Invalid Input");
            System.exit(0);
        }

        in.close();
        out.close();
    }
}