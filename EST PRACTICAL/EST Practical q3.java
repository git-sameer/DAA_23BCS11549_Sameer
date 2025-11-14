import java.util.*;

public class Main {
    public static String reorganizeString(String s) {
        int n = s.length();
        
        // Count frequency
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Max heap storing (count, char)
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.offer(new int[]{freq[i], i});
        }

        StringBuilder sb = new StringBuilder();
        
        while (pq.size() > 1) {
            int[] first = pq.poll();
            int[] second = pq.poll();

            sb.append((char)(first[1] + 'a'));
            sb.append((char)(second[1] + 'a'));

            if (--first[0] > 0) pq.offer(first);
            if (--second[0] > 0) pq.offer(second);
        }

        // If one char remains
        if (!pq.isEmpty()) {
            int[] last = pq.poll();
            if (last[0] > 1) return "-1"; // Not possible
            sb.append((char)(last[1] + 'a'));
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(reorganizeString(s));
    }
}
