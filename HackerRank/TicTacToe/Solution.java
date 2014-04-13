import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

/* Complete the function below to print 2 integers separated by a single space which will be your next move */
    static void nextMove(String player, String [] board) {
        String [][] brand = new  String[3][3];
        String [][] br = new  String[3][3];
        for (int i =0 ; i < 3;i++) {
            br[i] = board[i].split("");
            for (int j =1 ; j < 4;j++) {
                //System.out.print(br[i][j]);
                brand[i][j-1] = br[i][j];
            }
                //System.out.println("");
        }
        ArrayList<Point> array;
        array = possibleSolutions(player,brand);
//        System.out.println("Array Size :"+ array.size());
        evaluateSolutions(player,brand,array);
    }

    static ArrayList possibleSolutions(String player,String [][] board) {
            ArrayList<Point> list = new ArrayList<Point>();
            for (int i =0;i<3;i++) {
                for (int j =0;j<3;j++) {
  //                      System.out.println(" Board"+board[i][j]);
                    if ("_".equals(board[i][j]) ) {
    //                    System.out.println("added");
                        list.add(new Point(i,j));
                    }
                }
            }
            return list;
    }
    
    static void evaluateSolutions(String player,String [][] board,ArrayList<Point> list) {
        for ( int i =0; i < list.size();i++) {
            System.out.println("Evaluating"+list.get(i).getX() + " " +list.get(i).getY());
        }
    }

    static int isItSolution(String player,String [][] board) {
        
       return 0; 
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String player;
        String board[] = new String[3];

        //If player is X, I'm the first player.
        //If player is O, I'm the second player.
        player = in.next();

        //Read the board now. The board is a 3x3 array filled with X, O or _.
        for(int i = 0; i < 3; i++) {
            board[i] = in.next();
        }

        nextMove(player,board);   
    
    }
}
class Point {
int x,y;
Point( int a,int b) {
    x=a;
    y=b;
}
int getX() {
    return x;
}

int getY() {
    return y;
}

}

