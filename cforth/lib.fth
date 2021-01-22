
: array: ( n -- ) ( i -- addr)
    create cells allot
    does> swap cells + 
;

: carray: ( n -- ) ( i -- addr)
    create chars allot
    does> swap cells + 
;

create masks #128 c, #64 c, #32 c, #16 c, #8 c, #4 c, #2 c, #1 c,

: bit-array ( len -- ) ( i -- m a) 
    create allot
    does> 
        swap 8 /mod masks + c@ -rot + ;
