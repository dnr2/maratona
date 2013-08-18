import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		if( a == 1){
			System.out.println("1");
		}else {
			BigInteger resp = new BigInteger("4");
			BigInteger sum = new BigInteger("4");
			for (int i = 2; i < a; i++) {
				resp = resp.add(sum);
				if( i % 2 == 1) sum = sum.multiply(new BigInteger("2"));
			}
			System.out.println(resp.toString());
		}
	}	
}