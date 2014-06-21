import java.util.*;
import java.math.*;

public class Main(){
	
	static int[] arr = new int[65];
	static int[] prim = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	static BigInteger maxv = (new BigInteger("2")).pow(new BigInteger("63"));
	static BigInteger[] fat = new BigInteger[64];
	Map<BigInteger,BigInteger> hash = new HashMap<BigInteger,BigInteger>();
	
	static boolean check( BigInteger a, int b ){
		return maxv.compareTo( a.multiply( new BigInteger(""+b))) > 0;
	}
	
	static BigInteger fn(){
		int sum = 0;
		BigInteger div = new BigInteger("1");
		for(int i =0; i < 25; i++){ //TODO may be more 
			div.multiply( fat[arr[i]]);
			sum += arr[i];			
		}
		return fat[sum].divide(div) ;		
	}
	
	static void rec( BigInteger mul, int pos){
		BigInteger v = new BigInteger( mul.toString() );
		for(int i = 1; i < 65; i++){
			if( pos > 0 && i > arr[pos-1]) break;
			if( check( v, prim[pos] ) ){
				arr[pos] = i;
				v.multiply(new BigInteger( ""+prim[pos] ) );
				BigInteger fnum = fn();
				if(hash.hasKey(fnum)){
					hash.put( fnum, v.min( hash.get(fnum)) );
				} else {
					hash.push( fnum, v );
				}
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
			print(fat[i].toString()+ "\n");
		}
		while(!in.hasNext()){
			String num = in.next();
		}		
	}
}