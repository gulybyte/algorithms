function ceaserCipherShiftChar(ASCIIValue, shift, toNormalizeASCIIValue)
    local normalizeASCIIValue = ASCIIValue - toNormalizeASCIIValue

    local addShiftWithNormalize = (normalizeASCIIValue + shift) % 26

    local normalizeToRealASCIIValue = addShiftWithNormalize + toNormalizeASCIIValue

    local asciiToChar = string.char(normalizeToRealASCIIValue)

    return asciiToChar
end

function crypt(shift, key)
    local result = ''
    for i = 1, #key do
        local currentPositionKeyCharacter = key:sub(i, i)
        local ASCIIValue = string.byte(currentPositionKeyCharacter)

        if ASCIIValue >= 65 and ASCIIValue <= 90 then -- if upper case
            result = result .. ceaserCipherShiftChar(ASCIIValue, shift, 65)
        elseif ASCIIValue >= 97 and ASCIIValue <= 122 then -- if lower case
            result = result .. ceaserCipherShiftChar(ASCIIValue, shift, 97)
        else -- if never charcter
            result = result .. currentPositionKeyCharacter
        end
    end

    return result
end

function encryption(encryptionKey)
    local shift = 3
    local cipherText = crypt(shift, encryptionKey)
    return cipherText
end

function decryption(decryptionKey)
    local shift = -3
    local plainText = crypt(shift, decryptionKey)
    return plainText
end


local plainText = 'ABC'
local cipherText = encryption(plainText)
local cipherTextToPlainText = decryption(cipherText)

print('plain text: ' .. plainText)
print('ecryption: ' .. cipherText)
print('deryption: ' .. cipherTextToPlainText)


