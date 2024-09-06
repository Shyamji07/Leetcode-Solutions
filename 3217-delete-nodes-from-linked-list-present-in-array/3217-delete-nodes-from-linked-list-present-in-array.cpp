class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create an unordered_set for efficient lookup of values in nums
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        // Handle the case where the head node needs to be removed
        while (head != nullptr && valuesToRemove.contains(head->val)) {
            head = head->next;
        }

        // If the list is empty after removing head nodes, return nullptr
        if (head == nullptr) {
            return nullptr;
        }

        // Iterate through the list, removing nodes with values in the set
        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.contains(current->next->val)) {
                // Skip the next node by updating the pointer
                current->next = current->next->next;
            } else {
                // Move to the next node
                current = current->next;
            }
        }

        return head;
    }
};