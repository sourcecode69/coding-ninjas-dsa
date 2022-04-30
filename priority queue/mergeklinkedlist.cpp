  ListNode* mergeKLists(vector<ListNode*>& lists) {
   priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        
        for (int i = 0; i < lists.size(); i++) {
            ListNode* node = lists[i];
            while (node != NULL) {
                pq.push({node->val, node});
                node = node -> next;
            }
        }
        
        ListNode* head = NULL;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        
        while (!pq.empty()) {
            if (head == NULL) {
                head = pq.top().second;
            }
            
            temp = pq.top().second;
            if (prev != NULL) {
                prev->next = temp; 
            }
            
            prev = temp;
            pq.pop();
        }
        
        return head;
        
    }
};
