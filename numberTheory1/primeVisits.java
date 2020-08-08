import java.util.*;
public class Main{
    static Scanner sc = new Scanner(System.in);
public static void calPrimes(int primes[])
{
    for (int i = 3; i <= 1000000; i += 2)
    {
        primes[i] = 1;
    }
    for (int i = 3; i*i <= 1000000; i += 2)
    {  
        if(primes[i]==1){
            
        
        for (int j = i * i; j <= 1000000; j += i)
        {
            primes[j] = 0;
        }
    }}
}
public static void main(String[] args)
{
    int[] primes = new int[1000005];
    calPrimes(primes);
    primes[1] = 0;
    primes[2] = 1;
    int csum[]= new int[1000005];
    for (int i = 1; i <= 1000000; i++)
    {
        csum[i] = csum[i - 1] + primes[i];
    }
    int t = sc.nextInt();
    while (t-->0)
    {
        int a, b;
        a = sc.nextInt();
        b = sc.nextInt();
        System.out.println(csum[b] - csum[a - 1]);
    }

}}