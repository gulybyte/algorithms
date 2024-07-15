section .data
    vector dd 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, -1

section .text
    global StaticImmutableVector

StaticImmutableVector:
    lea     rax,    [rel vector]
    ret
