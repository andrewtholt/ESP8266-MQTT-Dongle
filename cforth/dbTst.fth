s" dbtst.fth" $find [if]
    execute
[else]
    marker dbtst.fth
[then]

\ requires activeBoolean.fth
requires nvs.fth


: set-tst
    ." Set some data ..." cr
    s" TEST" s" TWO" db-put abort" ... failed"
    ." ... done" cr

    s" WIFI_SSID"        s" HoltAtHome4" db-put abort" ... failed WIFI_SSID"
    s" WIFI_PASSWD" s" PassworD"      db-put abort" ... failed WIFI_PASSWD"
;

: get-tst
    ." Get some data ..." cr
    s" TEST" value-buffer db-get abort" ... failed"
    ." ... done" cr

    ." Let's see it >" .value cr
;

: get
    safe-parse-word  \ addr n
    $find
    if              \ xt
    else        \ addr n
        value-buffer db-get abort" get failed."
    then
;

: tst
    db-init
    set-tst
    get-tst
;

