import java.util.*;
 class ain {
    static Scanner sc = new Scanner(System.in);
    public static void main(String args[]) {
        double per = 0;
        double curr = 1;
        int i = 1;
       for(;curr>per;i++){
           curr*= (double)(365-i)/365;
           per = 1 - curr;
           
       }
       
        System.out.println(i);
    }
}