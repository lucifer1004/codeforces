pub fn next_permutation(nums: &mut [i32]) -> bool {
    use std::cmp::Ordering;
    // or use feature(array_windows) on nightly
    let last_ascending = match nums.windows(2).rposition(|w| w[0] < w[1]) {
        Some(i) => i,
        None => {
            nums.reverse();
            return false;
        }
    };

    let swap_with = nums[last_ascending + 1..]
        .binary_search_by(|n| i32::cmp(&nums[last_ascending], n).then(Ordering::Greater))
        .unwrap_err(); // cannot fail because the binary search will never succeed

    nums.swap(last_ascending, last_ascending + swap_with);
    nums[last_ascending + 1..].reverse();
    true
}