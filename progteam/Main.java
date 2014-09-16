import java.util.*;
import java.math.*;

public class Main{
	
	static int[] arr = new int[65];
	static int[] prim = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	static BigInteger maxv = (new BigInteger("2")).pow(63);
	static BigInteger[] fat = new BigInteger[64];
	static Map<BigInteger,BigInteger> hash = new HashMap<BigInteger,BigInteger>();
	
	static boolean check( BigInteger a, int b ){
		return maxv.compareTo( a.multiply( new BigInteger(""+b))) > 0;
	}
	
	static BigInteger fn(int pos){
		int sum = 0;
		BigInteger div = new BigInteger("1");
		for(int i =0; i < pos+1; i++){
			div = div.multiply( fat[arr[i]]);
			sum += arr[i];	
		}
		BigInteger ret =  fat[sum].divide(div) ;		
		if( ret.compareTo( maxv ) >= 0 ) return new BigInteger("-1");
		return ret;
	}
	
	static void rec( BigInteger mul, int pos){		
		BigInteger v = new BigInteger( mul.toString() );
		for(int i = 1; i < 65; i++){
			if( pos > 0 && i > arr[pos-1]) break;
			if( check( v, prim[pos] ) ){
				arr[pos] = i;
				v = v.multiply(new BigInteger( "" + prim[pos] ) );
				BigInteger fnum = fn(pos);
				if( fnum.compareTo(new BigInteger("0")) < 0) continue;				
				if(hash.containsKey(fnum)){	
					hash.put( fnum, v.min( hash.get(fnum)) );
				} else {
					hash.put( fnum, v );
				}				
				rec( v , pos + 1);
			}
		}
	}
	
	static void print(String a){
		System.out.print(a);
	}
	
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		fat[0] = new BigInteger("1");
		for( int i = 1; i < 64; i++){
			fat[i] = fat[i-1].multiply( new BigInteger("" + i ) );			
		}
		rec( new BigInteger("1"), 0);	
		while(in.hasNext()){
			BigInteger num = new BigInteger(""+in.next());
			print( num + " " + hash.get(num) + "\n");
		}		
	}
}