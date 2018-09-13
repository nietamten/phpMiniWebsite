#/bin/bash
#sprawdza ktore mac'i  z listy dzialaja
for mac in `cat MAClist`
do
killall dhcpcd 
echo MAC: $mac
ifconfig $1 down
ifconfig $1 hw ether $mac
iwconfig $1 essid $2
ifconfig $1 up
dhcpcd $1
ifconfig $1 |grep addr
host wp.pl
done

exit 0
