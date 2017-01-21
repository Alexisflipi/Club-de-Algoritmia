import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    while (in.hasNext()) {
      BigDecimal base = in.nextBigDecimal();
      int power = in.nextInt();
      BigDecimal num = base.pow(power);
      String str = new String(num.toPlainString());
      if (str.length() == 1) {
        System.out.println(str);
        continue;
      }
      int start = 0;
      while (str.charAt(start) == '0') {
        start++;
      }
      int end = str.length() - 1;
      while (str.charAt(end) == '0') {
        end--;
      }
      if (str.charAt(end) == '.') {
        end--;
      }
      System.out.println(str.substring(start, end + 1));
    }
  }
}
