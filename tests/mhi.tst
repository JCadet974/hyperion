*Testcase mhi
sysclear
archmode z
r     60=00020000000000000000000000000000
r    1A0=00000001800000000000000000000200
r    1D0=0002000180000000FFFFFFFFDEADDEAD
r    200=412000211852A72C00021862B2220040
r    210=41322001B2B20060
restart
suspend .1
*Compare
gpr
*Gpr 2 0042
*Gpr 3 0085
*Gpr 4 000000000000000
*Done