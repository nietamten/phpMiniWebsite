#/bin/bash
#sprawdza czy polaczenie z danym mac'iem dziala

killall dhcpcd dhclient

echo MAC: $1
echo klade interfejs
ifconfig $2 down
echo zmieniam mac
ifconfig $2 hw ether $1
iwconfig $2 essid $3
echo podnosze
ifconfig $2 up
echo uruchamiam dhcpcd
dhcpcd $2
echo robie pierdoly
ifconfig $2 |grep addr
host wp.pl

exit 0
