import java.util.*;

public class Solution {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            scanner.nextLine();
            String s = scanner.nextLine();
            int[] a = Arrays.stream(s.split(" ")).mapToInt(Integer::parseInt).toArray();
        }
    }
}