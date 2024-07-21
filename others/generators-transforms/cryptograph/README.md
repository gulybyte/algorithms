### AES, BCRYPT... Simetricas


<!-- falar sobre porque não pode ser um simples gerador aleatorio a partir da seed, como hash, pois como visto nos geradores aleatorios, mesmo a seed seja algo como a data e hora, ainda assim o que será gerado será deterministico portanto possivelmente calculado para uma possivel reversão sabendo assim a seed ... sla, nem sei direito, vou ver conforme vou fazendo -->


## About Cryptography ([reference](https://www.geeksforgeeks.org/cryptography-introduction/?ref=lbp))

### Types
 1. **Symmetric-key cryptography:** This type of cryptography involves the use of a single key to encrypt and decrypt data
 2. **Asymmetric-key cryptography:** Asymmetric-key cryptography, also known as public-key cryptography, uses a pair of keys – a public key and a private key – to encrypt and decrypt data. The public key is available to anyone, while the private key is kept secret by the owner.

### Challenges of Cryptography
While cryptography is a powerful tool for securing information, it also presents several challenges, including:

Key management: Cryptography relies on the use of keys, which must be managed carefully to maintain the security of the communication.
Quantum computing: The development of quantum computing poses a potential threat to current cryptographic algorithms, which may become vulnerable to attacks.
Human error: Cryptography is only as strong as its weakest link, and human error can easily compromise the security of a communication.

## Symetric
![](https://media.geeksforgeeks.org/wp-content/uploads/20210224215653/fgfdgrfgrf21.png)

Os mais básicos, onde se souber os parametros (secretKey) fácilmente com cyptanalysis ou brute force podemos quebra-los, os chamados algoritmos de cifra, mas nem por isso ele são ruins, pois servem de base para algoritmo mais atuais e robustos
 - [Ceaser or ROT13 Algorithm](elementar/cipher-algorithms/basic-cipher-algorithm-rot13-ceaser/)
 - [Vigenere Cipher](elementar/cipher-algorithms/vigenere-cipher/)



## Asymmetric


encriptar(texto)


# referencia
 - https://www.geeksforgeeks.org/cryptography-tutorial/?ref=lbp
 - https://hackingnaweb.com/criptografia/entendendo-algoritmo-rsa-de-verdade/

<!-- - os 3 videos do akita sobre o assunto, e Knuth vol 2 -->
