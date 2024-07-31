function factorial(num)
    if num < 0 then
        print("invalid input")
        return;
    elseif num == 0 then
        return 1;
    else
        return (num * factorial(num - 1))
    end
end

function eulerNumber(terms)
    local result = 0
    for i = 0, terms do
        local formula = 1 / factorial(i)
        result = result + formula
    end
    return result
end


local number = 20
local result = factorial(number)

print(number .. '! = ' .. result)
print('number e ≈ ' .. eulerNumber(50))

