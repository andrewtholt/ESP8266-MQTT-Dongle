
0 value db-init-run

32 constant /db-buffer
/db-buffer buffer: db-buffer

db-buffer /db-buffer 2constant value-buffer

: db-init
    db-init-run 0= if
        ." Open db ..." cr
        s" settings" db-open abort" ...  failed"

        ." ... done" cr
        value-buffer erase
        -1 to db-init-run
    then
;
: (db-get) { name nlen val vlen -- }

    db-init-run 0= abort" Init not run"

    val vlen erase
    name nlen val vlen db-get
;

: (db-set) { name nlen val vlen -- }
    db-init-run 0= abort" Init not run"

    name nlen val vlen
    db-put
;

: nvs-get
    safe-parse-word \ db Name len
    value-buffer

    (db-get) 0= if
        db-buffer count type cr
    else
        ." Not found" cr
    then
;

: nvs-set
    safe-parse-word
    safe-parse-word
    (db-set) 0<> if
        ." Failed" cr
    then
;

: .value
    db-buffer count type
;


