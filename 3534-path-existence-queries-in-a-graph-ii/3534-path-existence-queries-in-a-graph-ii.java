import java.util.*;

class Solution {
    static class Element {
        int val;
        int originalIdx;

        Element(int val, int originalIdx) {
            this.val = val;
            this.originalIdx = originalIdx;
        }
    }

    public int[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        Element[] A = new Element[n];
        int[] posInSorted = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = new Element(nums[i], i);
        }

        // Sort elements by their values
        Arrays.sort(A, (a, b) -> Integer.compare(a.val, b.val));
        for (int i = 0; i < n; i++) {
            posInSorted[A[i].originalIdx] = i;
        }

        int LOG = 18; // Since N <= 10^5, 2^17 = 131072
        int[][] up = new int[LOG][n];
        int[][] down = new int[LOG][n];

        // 1. Compute 2^0 jumps (base cases) using binary search
        for (int i = 0; i < n; i++) {
            // Forward greedy jump: largest element <= A[i].val + maxDiff
            int targetValUp = A[i].val + maxDiff;
            int low = i, high = n - 1, bestUp = i;
            while (low <= high) {
                int mid = (low + high) >>> 1;
                if (A[mid].val <= targetValUp) {
                    bestUp = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            up[0][i] = bestUp;

            // Backward greedy jump: smallest element >= A[i].val - maxDiff
            int targetValDown = A[i].val - maxDiff;
            low = 0; high = i; int bestDown = i;
            while (low <= high) {
                int mid = (low + high) >>> 1;
                if (A[mid].val >= targetValDown) {
                    bestDown = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            down[0][i] = bestDown;
        }

        // 2. Build the binary lifting tables
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
                down[k][i] = down[k - 1][down[k - 1][i]];
            }
        }

        // 3. Answer each query in O(log N)
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (u == v) {
                result[i] = 0;
                continue;
            }

            int idxU = posInSorted[u];
            int idxV = posInSorted[v];

            if (A[idxU].val == A[idxV].val) {
                result[i] = 1; // Same value but different indices mean direct edge
                continue;
            }

            int steps = 0;
            if (A[idxU].val < A[idxV].val) {
                // Lift upwards towards larger values
                for (int k = LOG - 1; k >= 0; k--) {
                    int nextIdx = up[k][idxU];
                    if (A[nextIdx].val < A[idxV].val) {
                        steps += (1 << k);
                        idxU = nextIdx;
                    }
                }
                // Check if one final step can bridge or reach the target
                int finalIdx = up[0][idxU];
                if (A[finalIdx].val >= A[idxV].val) {
                    result[i] = steps + 1;
                } else {
                    result[i] = -1;
                }
            } else {
                // Lift downwards towards smaller values
                for (int k = LOG - 1; k >= 0; k--) {
                    int nextIdx = down[k][idxU];
                    if (A[nextIdx].val > A[idxV].val) {
                        steps += (1 << k);
                        idxU = nextIdx;
                    }
                }
                // Check if one final step can bridge or reach the target
                int finalIdx = down[0][idxU];
                if (A[finalIdx].val <= A[idxV].val) {
                    result[i] = steps + 1;
                } else {
                    result[i] = -1;
                }
            }
        }

        return result;
    }
}