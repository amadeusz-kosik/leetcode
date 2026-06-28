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

    fn _add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, carry: i32) -> Option<Box<ListNode>> {
        return match (l1, l2, carry) {
            (None, None, 0) => {
                return None;
            }

            (None, None, c) => {
                return Some(Box::new(ListNode { next: None, val: c }));
            }

            (Some(lnode), None, 0) => {
                return Some(lnode);
            }

            (Some(lnode), None, c) => {
                let new_sum   = lnode.val + c;
                let new_digit = new_sum % 10;
                let new_carry = new_sum / 10;

                let new_next = Self::_add_two_numbers(lnode.next, None, new_carry);
                let new_node = Box::new(ListNode { next: new_next, val: new_digit });
                return Some(new_node);
            }

            (None, Some(rnode), 0) => {
                return Some(rnode);
            }

            (None, Some(rnode), c) => {
                let new_sum   = rnode.val + c;
                let new_digit = new_sum % 10;
                let new_carry = new_sum / 10;

                let new_next = Self::_add_two_numbers(None, rnode.next, new_carry);
                let new_node = Box::new(ListNode { next: new_next, val: new_digit });
                return Some(new_node);
            }

            (Some(lnode), Some(rnode), c) => {
                let new_sum   = lnode.val + rnode.val + c;
                let new_digit = new_sum % 10;
                let new_carry = new_sum / 10;

                let new_next = Self::_add_two_numbers(lnode.next, rnode.next, new_carry);
                let new_node = Box::new(ListNode { next: new_next, val: new_digit });
                return Some(new_node);
            }
        }
    }

    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        return Self::_add_two_numbers(l1, l2, 0);
    }
}