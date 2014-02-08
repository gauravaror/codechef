import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int puzzle[][] = new int[k][k];
        int solution[][] = new int[k][k];
        int sol=0;
        for ( int i=0;i < k;i++) {
            for ( int j=0;j < k;j++) {
                puzzle[i][j] = in.nextInt();
                solution[i][j] = sol;
                sol++;                
            }
        }      
        for ( int i=0;i < k;i++) {
            for ( int j=0;j < k;j++) {
                System.out.print(puzzle[i][j]+" "); 
            }
            System.out.println("");
        }      
    }

    private static costConfig() {
        
    }
}
