
1 constant cmd-set       \ Set name to value, return nothing
2 constant cmd-get       \ get value assigned to name return value to stdout
3 constant cmd-to-stack  \ get value assigned to name onto stack.
4 constant cmd-write     \ set value return nothing
5 constant cmd-read      \ get value assigned to name onto stack.
\ 
\ cmd-set and cmd-get are actions can be overriden (see below).
\ by default cmd-set sets the local value.
\            cmd-get displays the value and then sets it to 0
\ 
\ cmd-write and read cannot be overriden, cmd-read is non-destructive.
\ 
\ <set-xt> <get-xt> mk-active-boolean <name>
\ 
\ the xt's are of words to run when set or get are called.
\ If they are 0 this acts like set-boolean
\
\ e.g: ' get-act ' set-act mk-active-boolean fred
\
\ Note: A read is destructive it sets the variable to false after every read.
\ TODO: Pass address to SET/GET callbacks.
\
: mk-active-boolean
    create
        0 ,     \ value
        ,     \ SET action
        ,     \ GET action
    does>
    \
    \ Stack : <cmd> <addr of value>
    \
    swap
    case
        cmd-set of
            \ 
            \ Now if the set action is non zero execute it.
            \ 
            dup cell+ @ ?dup if
                execute
            else
                !
            then
        endof

        cmd-get of
            dup dup
            @
            swap 0 swap !
            swap 2 cells + @ ?dup 

            if
                execute
            then
            . cr
        endof

        cmd-to-stack of
            dup @               \ addr n
            swap 0 swap !
        endof

        cmd-read of
            @
        endof

        cmd-write of
            !
        endof
        drop
    endcase
;

: set-act
    ." SET Action" cr
    .s cr

    !
    
;

: get-act
\    ." GET Action" cr
    if
        ." TRUE" cr
    else
        ." FALSE" cr
    then
;

true constant TEST

TEST [if]
\ ' get-act ' set-act mk-active-boolean ted
\ 
\ cmd-get ted 
\ 1 cmd-set ted
\ cmd-get ted 
\ 
' get-act ' set-act mk-active-boolean bill
0 0 mk-active-boolean ted

clear
cmd-get ted 
42 cmd-set ted
.s clear
cmd-get ted 
.s clear
cmd-to-stack ted
.s clear

[then]

