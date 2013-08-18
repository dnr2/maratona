import java.util.*;
import java.math.*;

public class Main {		
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			int a = in.nextInt();
			int b = in.nextInt();
			if(a==b&&b==0)break;			
			BigInteger x = new BigInteger("1"), y = new BigInteger(""+a);
			while(b>0){
				if((b&1)!=0){ x=x.multiply(y);}
				y=y.multiply(y);b/=2;
			}
			System.out.println(x);
		}
	}
}
