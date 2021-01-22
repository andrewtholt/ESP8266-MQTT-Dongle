
1 constant cmd-set          \ Set name to value, return nothing
2 constant cmd-get          \ get value assigned to name return value to stdout
3 constant cmd-to-stack  \  get value assigned to name onto stack.
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
                drop
            then
        endof

        cmd-get of
            dup dup
            @
            swap 0 swap !
            swap 2 cells + @ ?dup if
                execute
            else
                drop
            then
        endof
        cmd-to-stack of
            dup @               \ addr n
            swap 0 swap !
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
' get-act ' set-act mk-active-boolean ted

cmd-get ted 
1 cmd-set ted
cmd-get ted 
[then]

