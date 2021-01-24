convert :: Read a => String -> [a]
convert = map read . words

main :: IO ()
main = do
  line <- getLine
  let list = convert line :: [Integer]
  print(list)
