function cipherShiftChar(ASCIIValue, shift, toNormalizeASCIIValue)
    return string.char(((ASCIIValue - toNormalizeASCIIValue + shift) % 26) + toNormalizeASCIIValue)
end

function cipherAlgorithm(shift, key)
    local result = ''
    for i = 1, #key do
        local currentPositionKeyCharacter = key:sub(i, i)
        local ASCIIValue = string.byte(currentPositionKeyCharacter)

        if ASCIIValue >= 65 and ASCIIValue <= 90 then -- if upper case
            result = result .. cipherShiftChar(ASCIIValue, shift, 65)
        elseif ASCIIValue >= 97 and ASCIIValue <= 122 then -- if lower case
            result = result .. cipherShiftChar(ASCIIValue, shift, 97)
        else -- if never charcter
            result = result .. currentPositionKeyCharacter
        end
    end

    return result
end

function encrypt(encryptionKey, secretKey)
    local shift = secretKey
    local cipherText = cipherAlgorithm(shift, encryptionKey)
    return cipherText
end

function decrypt(decryptionKey, secretKey)
    local shift = 0 - secretKey
    local plainText = cipherAlgorithm(shift, decryptionKey)
    return plainText
end


local plainText = 'ABC'
local secretKey = 13 -- Value of Shift
local cipherText = encrypt(plainText, secretKey)
local cipherTextToPlainText = decrypt(cipherText, secretKey)

print('plain text: ' .. plainText)
print('ecryption: ' .. cipherText)
print('deryption: ' .. cipherTextToPlainText)


