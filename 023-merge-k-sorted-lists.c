int find_min_head(struct ListNode **lists, int listsSize) {
    int min_index = 0;

    for(int i = 1; i < listsSize; ++ i) {
       if((lists[min_index] -> val) > (lists[i] -> val))
            min_index = i;
    }
    
    return min_index;
}

int initial_prune(struct ListNode **lists, int listsSize) {
    int result_size = 0;

    int i_write = 0;
    int i_read  = 0;

    while(i_read < listsSize) {
        if(lists[i_read] != NULL) {
            if(i_read != i_write) {
                lists[i_write] = lists[i_read];
            }

            ++ i_read;
            ++ i_write;
        } else {
            ++ i_read;
        }
    }

    return i_write;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *result = NULL;
    struct ListNode *last   = NULL;

    listsSize = initial_prune(lists, listsSize);

    if(listsSize == 1) {
        return lists[0];
    }
    
    while(listsSize > 0) {
        if(listsSize == 1) {
            last -> next = lists[0];
            return result;
        } else {
            int min_head_index = find_min_head(lists, listsSize);

            if(result == NULL) {
                result = lists[min_head_index];
                last   = lists[min_head_index];
            } else {
                last -> next = lists[min_head_index];
                last = last -> next;
            }
            
            lists[min_head_index] = lists[min_head_index] -> next;

            // Detect empty list, exclude it from iterating
            if(lists[min_head_index] == NULL) {
                if(min_head_index < listsSize - 1)
                    lists[min_head_index] = lists[listsSize - 1];

                -- listsSize;
            }
        }       
    }

    return result;
}
