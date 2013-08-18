//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=406
//#tag adhoc

import java.util.*;
import java.math.*;

public class Main {		
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			String str = in.nextLine();
			System.out.println(str);
			char op;
			str = str.replace(" ", "");
			int x = str.indexOf('+');
			BigInteger a ,b,c;
			if( x >= 0 ){
				a = new BigInteger(str.substring(0, x));
				b = new BigInteger(str.substring(x+1, str.length()));
				c = a.add(b);
				
			} else {
				x = str.indexOf('*');
				a = new BigInteger(str.substring(0, x));
				b = new BigInteger(str.substring(x+1, str.length()));
				c = a.multiply(b);
			}
			if( a.compareTo( new BigInteger( "" + 2147483647 )) > 0){
				System.out.println("first number too big");
			}
			if( b.compareTo( new BigInteger( "" + 2147483647 )) > 0){
				System.out.println("second number too big");
			}
			if( c.compareTo( new BigInteger( "" + 2147483647 )) > 0){
				System.out.println("result too big");
			}
		}
	}
}
