impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n == 0 { return 0; }
        if n == 1 { return 1; } 

        let un: usize = (n as usize);
        let mut values = vec![0; un + 1];

        values[0] = 0;
        values[1] = 1;

        for i in 2..un {
            values[i] = values[i - 1] + values[i - 2];
        }

        return values[un - 1] + values[un - 2];
    }
}