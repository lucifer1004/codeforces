# 1316C Primitive Primes

Since $p$ is a prime, there is no need to use FFT. We just need to find $a_i\not\equiv 0\pmod p$, and $b_j\not\equiv 0\pmod p$, and this is enough to ensure that $c_{i+j}\not\equiv 0\pmod p$.

Some languages cannot read inputs very fast, e.g., Python, Kotlin, which get TLE at Test 7.

Among the languages that can pass all tests, Rust (202 ms) is the fastest, followed by Go (233 ms) and C++ (576 ms).