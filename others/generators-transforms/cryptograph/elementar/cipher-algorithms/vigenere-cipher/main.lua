function vigenereCipherShiftChar(ASCIIValue, shiftValue, toNormalizeASCIIValue, isDecrypt)
    if isDecrypt then
        local C = ASCIIValue - toNormalizeASCIIValue
        local K = shiftValue
        local P = (C - K) % 26
        return string.char(P + toNormalizeASCIIValue)
    end

    local P = ASCIIValue - toNormalizeASCIIValue
    local K = shiftValue
    local C = (P + K) % 26
    return string.char(C + toNormalizeASCIIValue)
end

function vigenereCipher(text, keyword, isDecrypt)
    local result = ''
    local keywordLength = #keyword
    local keywordIndex = 1

    for i = 1, #text do
        local currentPositionKeyCharacter = text:sub(i, i)
        local ASCIIValue = string.byte(currentPositionKeyCharacter)
        local shiftValue = string.byte(keyword:sub(keywordIndex, keywordIndex)) - 65

        if ASCIIValue >= 65 and ASCIIValue <= 90 then -- if upper case
            result = result .. vigenereCipherShiftChar(ASCIIValue, shiftValue, 65, isDecrypt)
            keywordIndex = (keywordIndex % keywordLength) + 1
        elseif ASCIIValue >= 97 and ASCIIValue <= 122 then -- if lower case
            result = result .. vigenereCipherShiftChar(ASCIIValue, shiftValue, 97, isDecrypt)
            keywordIndex = (keywordIndex % keywordLength) + 1
        else -- if never charcter
            result = result .. currentPositionKeyCharacter
        end
    end

    return result
end

function encrypt(encryptionKey, secretKey)
    local cipherText = vigenereCipher(encryptionKey, secretKey, false)
    return cipherText
end

function decrypt(decryptionKey, secretKey)
    local plainText = vigenereCipher(decryptionKey, secretKey, true)
    return plainText
end


local plainText = 'attack'
local secretKey = 'KEY' -- Value of Shift
local cipherText = encrypt(plainText, secretKey)
local cipherTextToPlainText = decrypt(cipherText, secretKey)

print('plain text: ' .. plainText)
print('ecryption: ' .. cipherText)
print('deryption: ' .. cipherTextToPlainText)


