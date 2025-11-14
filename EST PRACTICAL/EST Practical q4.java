import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();

        List<Integer> ans = maxSlidingWindow(nums, k);
        for (int x : ans) System.out.print(x + " ");
    }

    public static List<Integer> maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<>();  // stores indices
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {

            // Remove elements out of this window
            if (!dq.isEmpty() && dq.peekFirst() <= i - k)
                dq.pollFirst();

            // Remove smaller elements from the back
            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[i])
                dq.pollLast();

            // Add current index
            dq.offerLast(i);

            // Starting from i >= k-1, we have valid windows
            if (i >= k - 1)
                result.add(nums[dq.peekFirst()]);
        }

        return result;
    }
}
