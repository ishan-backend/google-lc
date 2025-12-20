/**
 * MAXIMUM SUBARRAY SUM WITH K-DIFFERENCE
 * 
 * Problem: Find maximum sum of a subarray where any two elements differ by at most k
 * 
 * Example: nums = [1,2,3,5], k = 1
 * Output: 5 (subarray [5] or [2,3] both valid)
 * 
 * APPROACH: Prefix Sum + Hash Map
 * ═════════════════════════════════════════════════════════
 * 
 * Key Insight:
 *   - For each position, track the best previous position where nums[prev] ∈ [nums[i]-k, nums[i]+k]
 *   - Use hash map to store: value -> earliest good index (for maximum sum)
 *   - Use prefix sums to calculate subarray sum in O(1)
 */

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = LLONG_MIN;
        
        // ════════════════════════════════════════════════════════
        // PREFIX SUM ARRAY
        // ════════════════════════════════════════════════════════
        // psum[i] = sum of nums[0...i-1]
        // psum[0] = 0 (empty prefix)
        // Allows us to calculate subarray sum in O(1):
        // sum(nums[i...j]) = psum[j+1] - psum[i]
        
        vector<long long> prefixSum{0};
        
        // ════════════════════════════════════════════════════════
        // HASH MAP: value -> best index
        // ════════════════════════════════════════════════════════
        // For each unique value, store the index where it appeared
        // We keep the EARLIEST good index to maximize subarray sum
        // (starting from the leftmost valid position gives largest sum)
        
        unordered_map<int, int> valueToIndex;
        
        // ════════════════════════════════════════════════════════
        // MAIN LOOP: Process each element
        // ════════════════════════════════════════════════════════
        
        for (int i = 0; i < nums.size(); i++) {
            // Add current element to prefix sum
            prefixSum.push_back(prefixSum.back() + nums[i]);
            
            int currentNum = nums[i];
            
            // ════════════════════════════════════════════════════
            // CASE 1: Look for previous element = currentNum - k
            // ════════════════════════════════════════════════════
            // If some prev element equals (currentNum - k),
            // then abs(prev - current) = k ✓ Valid!
            // Calculate subarray sum from that position to current
            
            if (valueToIndex.count(currentNum - k)) {
                int prevIndex = valueToIndex[currentNum - k];
                long long subarraySum = prefixSum[i + 1] - prefixSum[prevIndex];
                maxSum = max(maxSum, subarraySum);
            }
            
            // ════════════════════════════════════════════════════
            // CASE 2: Look for previous element = currentNum + k
            // ════════════════════════════════════════════════════
            // If some prev element equals (currentNum + k),
            // then abs(prev - current) = k ✓ Valid!
            // Calculate subarray sum from that position to current
            
            if (valueToIndex.count(currentNum + k)) {
                int prevIndex = valueToIndex[currentNum + k];
                long long subarraySum = prefixSum[i + 1] - prefixSum[prevIndex];
                maxSum = max(maxSum, subarraySum);
            }
            
            // ════════════════════════════════════════════════════
            // CASE 3: Update hash map with current element
            // ════════════════════════════════════════════════════
            // Strategy: Keep the EARLIEST index of each value
            // 
            // Why earliest?
            //   - Starting from earliest gives longest subarray
            //   - Longest subarray = maximum sum (if all elements valid)
            // 
            // When to update?
            //   - If this value NOT seen before: Always add
            //   - If seen before but got negative contribution: 
            //     Replace with current (better starting point)
            
            bool isNewValue = !valueToIndex.count(currentNum);
            bool isEarlierGoodIndex = false;
            
            if (!isNewValue) {
                int prevIndex = valueToIndex[currentNum];
                long long contributionSoFar = prefixSum[i] - prefixSum[prevIndex];
                // If contribution is non-positive, current index is better
                isEarlierGoodIndex = (contributionSoFar <= 0);
            }
            
            if (isNewValue || isEarlierGoodIndex) {
                valueToIndex[currentNum] = i;
            }
        }
        
        // ════════════════════════════════════════════════════════
        // RETURN RESULT
        // ════════════════════════════════════════════════════════
        // If no valid subarray found (LLONG_MIN), return 0
        // Otherwise return the maximum sum found
        
        return (maxSum == LLONG_MIN) ? 0 : maxSum;
    }
};