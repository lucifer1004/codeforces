import GHC.Int

convert :: Read a => String -> [a]
convert = map read . words

main :: IO ()
main = do
  line <- getLine
  let [n, m, a] = convert line :: [GHC.Int.Int64]
  let x = (n - 1) `div` a + 1
  let y = (m - 1) `div` a + 1
  print (x * y)  