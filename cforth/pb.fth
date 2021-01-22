requires lib.fth

decimal

#24 #4 * constant /day
/day 7 * constant /week

7 array: day-ptr



here /week allot constant week

: time>minutes
    swap 60 * +
;

: minutes>slot
    15 /mod \ remainder slot

    swap    \ slot remainder

    8 < if
        dup 1- swap
    else 
        dup 1+
    then

;


