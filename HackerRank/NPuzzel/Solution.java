import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static HashSet<String> hash;
    static LinkedList<String> moves;
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int puzzle[][] = new int[k][k];
        int solution[][] = new int[k][k];
        int sol=0;
        int currentpostni=0;
        int currentpostnj=0;
        int currentcost=0;
        for ( int i=0;i < k;i++) {
            for ( int j=0;j < k;j++) {
                puzzle[i][j] = in.nextInt();
                solution[i][j] = sol;
                sol++;                
            }
        }      
        currentcost = 0;
        for ( int i=0;i < k;i++) {
            for ( int j=0;j < k;j++) {
                //System.out.print(puzzle[i][j]+" "); 
                if (puzzle[i][j] == 0) {
                    currentpostni = i;
                    currentpostnj = j;
                }
                if( puzzle[i][j] != solution[i][j] ) {
                    currentcost = currentcost + 1;
                }
                else {
                    currentcost = currentcost + Math.abs(puzzle[i][j] - solution[i][j]);
                }
            }
            //System.out.println("");
        }
        currentcost = calucost(puzzle,solution,k);
        hash = new HashSet<String>();
        moves = new LinkedList<String>();
        hash.add(getRepresentation(puzzle,k));   
        //System.out.println("Cost :"+ currentcost+" current post i j "+ currentpostni + " "+ currentpostnj);
        movezerotillend(puzzle,currentcost,currentpostni,currentpostnj,solution,k,-1);
      //  System.out.println(print(puzzle,solution,k)); 
        System.out.println(moves.size());
        for (int i =0 ; i< moves.size();i++) {
             System.out.println(moves.get(i));
        } 
    }
    
    public  static int movezerotillend(int[][] puzzle,int cost,int i,int j,int[][] solution,int k,int lastmove) {
        if (cost == 0) {
            return 0;
        }
        int left_cost=100000;
        int up_cost=100000;
        int right_cost=100000;
        int down_cost=100000;

        if (i < k && j-1 >= 0) {
          if (lastmove != 2) {
             left_cost = costConfig(puzzle,cost,i,j,solution,k,0);
         }
        }
        if (i-1 >= 0 && j < k) {
          if (lastmove != 3) {
         up_cost = costConfig(puzzle,cost,i,j,solution,k,1);
        }
        }
        if (i < k && j+1 < k) {
          if (lastmove != 0) {
         right_cost = costConfig(puzzle,cost,i,j,solution,k,2);
        }}
        if (i+1 < k && j < k) {
          if (lastmove != 1) {
         down_cost = costConfig(puzzle,cost,i,j,solution,k,3);
        }
        }
        
        int move =  minCost(left_cost,up_cost,right_cost,down_cost);
        System.out.println("MOVE :"+move+ "COST : L U R D"+left_cost+" "+up_cost+ " "+right_cost+ " "+down_cost);
        String rep ="";
    switch(move) {
    case 0:
            rep = getRepresentation(puzzle,k);
            puzzle[i][j] =  puzzle[i][j-1];
            puzzle[i][j-1] = 0;
            j = j-1;
            //System.out.println("=========================");
            //System.out.println(calucost(puzzle,solution,k));
            //System.out.println("=========================");
            hash.add(rep+getRepresentation(puzzle,k));
            moves.add("LEFT");
            return movezerotillend(puzzle,left_cost,i,j,solution,k,0);
    case 1:
             rep = getRepresentation(puzzle,k);
            puzzle[i][j] =  puzzle[i-1][j];
            puzzle[i-1][j] = 0;
            i = i-1;
            //System.out.println("=========================");
            //System.out.println(calucost(puzzle,solution,k));
            //System.out.println("=========================");
            hash.add(rep+getRepresentation(puzzle,k));
            moves.add("UP");
            return movezerotillend(puzzle,up_cost,i,j,solution,k,1);
    case 2:
            rep = getRepresentation(puzzle,k);
            puzzle[i][j] =  puzzle[i][j+1];
            puzzle[i][j+1] = 0;
            j = j+1;
            //System.out.println("=========================");
            //System.out.println(calucost(puzzle,solution,k));
            //System.out.println("=========================");
            hash.add(rep+getRepresentation(puzzle,k));
            moves.add("RIGHT");
            return movezerotillend(puzzle,right_cost,i,j,solution,k,2);
    case 3:
            rep = getRepresentation(puzzle,k);
            puzzle[i][j] =  puzzle[i+1][j];
            puzzle[i+1][j] = 0;
            i = i+1;
            //System.out.println("=========================");
            //System.out.println(calucost(puzzle,solution,k));
            //System.out.println("=========================");
            hash.add(rep+getRepresentation(puzzle,k));
            moves.add("DOWN");
            return movezerotillend(puzzle,down_cost,i,j,solution,k,3);
    }
        
        return -1;
    }

    private static int minCost(int left_cost,int up_cost,int right_cost,int down_cost) {

            int in_1,in_2,in_1_cost,in_2_cost;
           if ( left_cost != 100000 || right_cost != 100000 ) {
                if (left_cost > right_cost) {
                    in_1 = 2;
                    in_1_cost = right_cost;
                }
                else {
                    in_1 = 0;
                    in_1_cost = left_cost;
                }
           }
           else {
                in_1 = 100000;
                in_1_cost = 100000;
            }
           if ( up_cost != 100000 || down_cost != 100000 ) {
                if (up_cost > down_cost) {
                    in_2 = 3;
                    in_2_cost = down_cost;
                }
                else {
                    in_2 = 1;
                    in_2_cost = up_cost;
                }
           }
           else {
                in_2 = 100000;
                in_2_cost = 100000;
            }
            if ( in_1_cost  > in_2_cost) {
                return in_2;
            }
            else {
                return in_1;
            }
    }
    private static  int costConfig(int[][] puzzle,int score, int i,int j,int[][] solution,int k,int move) {
        
        int current_score=0;
        int aftermove_score=0;
        int calcost=0;
        boolean conta;
        String re="";
        switch (move) {

            case 0:
                re = getRepresentation(puzzle,k);
                puzzle[i][j] =  puzzle[i][j-1];
                puzzle[i][j-1] = 0;
                conta = hash.contains(re+getRepresentation(puzzle,k));
                calcost = calucost(puzzle,solution,k);
                puzzle[i][j-1] =  puzzle[i][j];
                puzzle[i][j] = 0;
                if (conta) {
                    return 100000;
                }
                else {
                    return calcost; 
                }
            case 1 :
                re = getRepresentation(puzzle,k);
                puzzle[i][j] =  puzzle[i-1][j];
                puzzle[i-1][j] = 0;
                conta =hash.contains(re+getRepresentation(puzzle,k));
                calcost = calucost(puzzle,solution,k);
                puzzle[i-1][j] =  puzzle[i][j];
                puzzle[i][j] = 0;
                if (conta) {
                    return 100000;
                }
                else {
                    return calcost; 
                }
            case 2 :
                re = getRepresentation(puzzle,k);
                puzzle[i][j] =  puzzle[i][j+1];
                puzzle[i][j+1] = 0;
                conta = hash.contains(re+getRepresentation(puzzle,k));
                calcost = calucost(puzzle,solution,k);
                puzzle[i][j+1] =  puzzle[i][j];
                puzzle[i][j] = 0;
                if (conta) {
                    return 100000;
                }
                else {
                    return calcost; 
                }
            case 3 :
                re = getRepresentation(puzzle,k);
                puzzle[i][j] =  puzzle[i+1][j];
                puzzle[i+1][j] = 0;
                conta = hash.contains(re+getRepresentation(puzzle,k));
                calcost = calucost(puzzle,solution,k);
                puzzle[i+1][j] =  puzzle[i][j];
                puzzle[i][j] = 0;
                if (conta) {
                    return 100000;
                }
                else {
                    return calcost; 
                }
        }
        return score;
    }

    private static String getRepresentation(int[][] puzzle,int k) {
            String rep = "";
            for ( int i=0;i < k;i++) {
                for ( int j=0;j < k;j++) {
                    rep = rep + puzzle[i][j];
                }
            }
        return rep;
    }

    private static int calucost(int[][] puzzle,int[][] solution,int k) {
            int cucost=0;
            for ( int l=0;l < k;l++) {
            for ( int m=0;m < k;m++) {
  //              System.out.print(puzzle[i][j]+" ");
                if (solution[l][m] != 0 ) {
                if( puzzle[l][m] != solution[l][m] ) {
                    cucost++;
                }
                }
            }
//            System.out.println("");
        }
        return cucost;
    }
    private static int calucost11(int[][] puzzle,int[][] solution,int k) {
            int cucost=0;
            for ( int i=0;i < k;i++) {
            for ( int j=0;j < k;j++) {
            for ( int l=0;l < k;l++) {
            for ( int m=0;m < k;m++) {
  //              System.out.print(puzzle[i][j]+" ");
  //              if (solution[i][j] != 0 ) {
                if( puzzle[l][m] != solution[i][j] ) {
                    cucost = cucost+ Math.abs(l-i) + Math.abs(m-j);
    //            }
                }
            }
//            System.out.println("");
        }
        }
        }
        return cucost;
    }
    private static int print(int[][] puzzle,int[][] solution,int k) {
            int cucost=0;
            for ( int i=0;i < k;i++) {
            for ( int j=0;j < k;j++) {
                System.out.print(puzzle[i][j]+" ");
                if( puzzle[i][j] != solution[i][j] ) {
                    cucost++;
                }
                else {
                }
            }
            System.out.println("");
        }
        return cucost;

}
} 
