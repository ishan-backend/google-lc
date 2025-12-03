class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();

        // Step 1: Replace all negative numbers with 0
        // Because negative numbers and zero do not matter for the first missing positive.
        for(int i = 0; i < len; i++){
            if(nums[i] < 0){
                nums[i] = 0;
            }
        }

        // Step 2: Use the index as a hash to mark the presence of a number.
        // If we see a value 'val', we mark index (val - 1) as negative.
        // - If nums[val-1] is positive -> make it negative.
        // - If nums[val-1] is zero -> mark with a special negative value (-(len+1))
        //     so we can distinguish between "0 means unused" and "present but marked".
        for(int i = 0; i < len; i++){
            int val = abs(nums[i]); // get absolute value because index might already be marked

            // Only care about values between [1, len]
            if(val >= 1 && val <= len){
                // Case 1: Already positive -> convert to negative (marking presence)
                if(nums[val - 1] > 0){
                    nums[val - 1] = -1 * nums[val - 1];
                }
                // Case 2: Value at index is 0 -> mark as special negative to indicate presence
                else if(nums[val - 1] == 0){
                    nums[val - 1] = -(len + 1);
                }
            }
        }

        // Step 3: The first index that still has a non-negative value
        // represents the first missing positive number.
        // If nums[i] >= 0 → i+1 is missing.
        for(int i = 0; i < len; i++){
            if(nums[i] >= 0){
                return i + 1;
            }
        }

        // If all positions were marked correctly, the first missing positive
        // is len + 1.
        return len + 1;
    }
};