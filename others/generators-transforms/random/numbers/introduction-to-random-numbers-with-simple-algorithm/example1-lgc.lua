function linearCongruentialGenerator(x0, a, c, m, n)
    local results = {}
    if a > 0 and m > 0 and c >= 0 and x0 >= 0 and a < m and c < m and x0 < m then
        for i = 1, n do
            x0 = (a * x0 + c) % m
            table.insert(results, x0)
        end
    else
        print('Condições não satisfeitas')
    end
    return results
end

local seed = 7
local multiplier = 7
local increment = 7
local modulus = 10

local n = 20

local lcg = linearCongruentialGenerator(seed, multiplier, increment, modulus, n)
local output = table.concat(lcg, " ")
print(output)


-- 6, 9, 0, 7, 6, 9, 0, 7
