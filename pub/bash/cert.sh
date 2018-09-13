#!/bin/bash
#tworzy certyfikat do strony internetowej
openssl genrsa -out key.pem 1024
openssl req -new -key key.pem -out request.pem
openssl x509 -req -days 200 -in request.pem -signkey key.pem -out certificate.pem
cat key.pem certificate.pem > /etc/lighttpd/ble.dnsalias.net/host.pem
#dodaj bazy danych javy
#keytool -import -alias vv -file certificate.pem -keypass abcd
#mobi/wtk/1/bin/mekeytool -import -alias vvcat key.pem certificate.pem
