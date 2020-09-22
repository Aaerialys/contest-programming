import java.math.*;
import java.util.*;

public class Test {
	public static void main(String[] args) {
		Scanner get = new Scanner (System.in);
		String in;
		BigInteger t=new BigInteger("1"); BigInteger s=new BigInteger("1");
		in=get.next();
		for(int i=0;i<in.length();i++) {
	        if(in.charAt(i)=='L')
	            t=t.multiply(new BigInteger("2"));
	        if(in.charAt(i)=='R')
	            t=t.multiply(new BigInteger("2")).add(s);
	        if(in.charAt(i)=='*')
	        {
	            t=t.multiply(new BigInteger("5")).add(s);
	            s=s.multiply(new BigInteger("3"));
	        }
		}
		System.out.println(t);
		//get.close();
	}

}