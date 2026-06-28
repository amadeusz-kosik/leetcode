impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut directories = Vec::new();

        for segment in path.split("/") {
            if segment == "" || segment == "." {
                continue;
            } else if segment == ".." {
                directories.pop();
            } else {
                directories.push(segment);
            }
        }

        return {
            if ! directories.is_empty() {
                let mut result = String::new();

                for directory in directories {
                    result.push('/');
                    result.push_str(directory);
                }

                result
            } else {
                String::from('/')
            }
        }
    }
}