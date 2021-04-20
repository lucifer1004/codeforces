fn mod_pow(mut x: usize, mut y: usize, m: usize) -> usize {
    let mut ans = 1usize;
    while y > 0 {
        if y & 1 == 1 {
            ans = ((ans as u128 * x as u128) % m as u128) as usize;
        }
        x = ((x as u128 * x as u128) % m as u128) as usize;
        y >>= 1;
    }
    ans
}

/// Test primality of a non-negative integer.
/// Reference: [Miller-Rabin primality test - Wikipedia](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)
pub fn miller_rabin(n: usize) -> bool {
    if n < 2 {
        false
    } else {
        for p in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29].iter() {
            if n % p == 0 { 
                return n == *p;
            }
        }

        let a = if n < 2_047 {
            vec![2]
        } else if n < 1_373_653 {
            vec![2, 3]
        } else if n < 9_080_191 {
            vec![31, 73]
        } else if n < 25_326_001 {
            vec![2, 3, 5]
        } else if n < 3_215_031_751 {
            vec![2, 3, 5, 7]
        } else if n < 4_759_123_141 {
            vec![2, 7, 61]
        } else if n < 1_122_004_669_633 {
            vec![2, 13, 23, 1_662_803]
        } else if n < 2_152_302_898_747 {
            vec![2, 3, 5, 7, 11]
        } else if n < 3_474_749_660_383 {
            vec![2, 3, 5, 7, 11, 13]
        } else {
            vec![2, 3, 5, 7, 11, 13, 17]
        };

        let r = (n - 1).trailing_zeros() as usize;
        let d = (n - 1) >> r;

        for ai in a {
            let mut x = mod_pow(ai % n, d, n);
            if x <= 1 || x == n - 1 {
                continue;
            }

            for _ in 0..r {
                if x == n - 1 {
                    break;
                }
                x = ((x as u128 * x as u128) % n as u128) as usize;
            }

            if x != n - 1 {
                return false;
            }
        }

        true
    }
}

/// Find all primes within [1,n] using an Euler sieve.
pub fn euler_sieve(n: usize) -> Vec<usize> {
    let mut vis = vec![false; n + 1];
    let mut primes = vec![];

    for i in 2..=n {
        if !vis[i] {
            primes.push(i);
        }
        for j in 0..primes.len() {
            if i * primes[j] > n {
                break;
            }
            vis[i * primes[j]] = true;
            if i % primes[j] == 0 {
                break;
            }
        }
    }

    primes
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_miller_rabin() {
        let a = 1_000_000_007usize;
        let b = 1_000_000_009usize;

        assert_eq!(miller_rabin(a), true);
        assert_eq!(miller_rabin(b), true);
        assert_eq!(miller_rabin(a * b), false);
    }

    #[test]
    fn test_euler_sieve() {
        let n = 1_000_000;
        let primes = euler_sieve(1_000_000);
        let mut ptr = 0;
        for i in 1..=n {
            if ptr < primes.len() && primes[ptr] < i {
                ptr += 1;
            }
            assert_eq!(miller_rabin(i), ptr < primes.len() && primes[ptr] == i);
        }
    }
}
