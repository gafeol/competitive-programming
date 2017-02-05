// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

// Please name your class Main
class Main {
	public static int MAXN = 110, BIT = (1<<13)+10;
	public static int n, k;
	public static BigInteger[][] dp = new BigInteger[MAXN][BIT];

	public static void main (String[] args) throws java.lang.Exception {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t > 0){
			n = in.nextInt();
			k = in.nextInt();
			for(int a=0;a<=n;a++){
				for(int b=0;b<BIT;b++){
					dp[a][b] = BigInteger.valueOf(-1);
				}
			}
			t--;
			System.out.println(go(0,(1<<k)-1).toString());
		}
	}

	public static BigInteger go(int i, int bm){
		if(BigInteger.valueOf(-1).compareTo(dp[i][bm]) != 0){
			return dp[i][bm];
		}
		dp[i][bm] = BigInteger.valueOf(0);
		if(i == n){
			//System.out.println("dp["+Integer.toString(i)+"]["+Integer.toBinaryString(bm)+"]: 1");
			return dp[i][bm] = BigInteger.valueOf(1);
		}
		if((bm&1) == 0){
			dp[i][bm] = go(i+1, bm>>1);
		}
		else{
			for(int e=0;e<=2*k;e++){
				if((bm&(1<<e)) != 0)
					continue;
				if(i + e - k < n){
					dp[i][bm] = dp[i][bm].add(go(i+1, ((bm|(1<<e))>>1)));
				}
			}
		}
		//System.out.println("dp["+Integer.toString(i)+"]["+Integer.toBinaryString(bm)+"]: "+dp[i][bm].toString());
		return dp[i][bm];
	}
}
