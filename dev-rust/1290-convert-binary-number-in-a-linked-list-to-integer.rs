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
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        let mut accumulator = 0;
        let mut current = head;

        loop {
            match current {
                Some(boxedNode) => {
                    accumulator = (accumulator * 2) + boxedNode.val;
                    current = boxedNode.next;
                }

                None => {
                    return accumulator;
                }
            }
        }
    }
}