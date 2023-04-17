import Data.List

main = interact $ unlines . map show . process . map (sort . map read . words) . tail . lines

process [] = []
process (_:x:y:xs) = process' 0 (take k rx) y + process'' 0 (drop k rx) y : process xs
    where k = length y 
          rx = reverse x

process' s [] _ = s
process' s (x:xs) (1:ys) = process' (s + 2 * x) xs ys
process' s (x:xs) (_:ys) = process' (s + x) xs ys

process'' s [] _ = s
process'' s xx (1:ys) = process'' s xx ys
process'' s xx@(x:xs) (y:ys) = process'' (s + xx !! (y - 2)) (drop (y - 2) xs) ys
