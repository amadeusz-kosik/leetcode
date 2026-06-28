// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {

    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
        match root {
            Some(root_rc) => {
                let root   = root_rc.borrow();
                let target = target_sum - root.val;

                (target == 0 && root.left.is_none() && root.right.is_none())
                    || Self::has_path_sum(root.left.clone(), target)
                    || Self::has_path_sum(root.right.clone(), target)
            },
            None => false
        }
    }
}