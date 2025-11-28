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
    pub fn merge_two_lists(list1: Option<Box<ListNode>>, list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> { return match (list1, list2) {
        (None, None) => {
            return None;
        }

        (Some(l), None) => {
            return Some(l);
        }

        (None, Some(l)) => {
            return Some(l);
        }

        (Some(l1), Some(l2)) => {
            if l1.val <= l2.val {
                let tail = Self::merge_two_lists(l1.next, Some(l2));
                return Some(Box::new(ListNode { next: tail, val: l1.val }));
            } else {
                let tail = Self::merge_two_lists(Some(l1), l2.next);
                return Some(Box::new(ListNode { next: tail, val: l2.val }));
            }

            return None;
        }

    }}
}
