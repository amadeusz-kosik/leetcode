// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
    pub fn delete_duplicates(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut current_node = head.as_mut();

        while let Some(current_ptr) = current_node {
            let mut next_node = current_ptr.next.take();

            while let Some(next_ptr) = next_node.as_mut() {
                if next_ptr.val == current_ptr.val {
                    next_node = next_ptr.next.take();
                } else {
                    current_ptr.next = next_node;
                    break;
                }
            }

            current_node = current_ptr.next.as_mut();
        }

        return head;
    }
}