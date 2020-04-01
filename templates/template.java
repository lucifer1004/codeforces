import java.util.*;

public class Solution {
  private static Scanner scanner = new Scanner(System.in);

  public static void main() {
    int t = scanner.nextInt();
    for (int caseNumber = 0; caseNumber < t; ++caseNumber) {
      int n = scanner.nextInt();
      String s = scanner.nextLine();
      int[] a =
          Arrays.stream(s.split(" ")).mapToInt(Integer::parseInt).toArray();
    }
  }
}