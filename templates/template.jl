function read_params(T::Type)
    line = readline()
    return map(x -> parse(T, x), split(line))
end

function solve()
    n = read_params(Int)[1]
    println(n)
end

solve()
