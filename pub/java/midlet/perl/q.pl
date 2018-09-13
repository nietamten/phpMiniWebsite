#!/usr/bin/perl -w

    use CGI; 
    use Net::Interface qw(:upper);
    use Net::Ping;
    use Net::Wake;
    use Net::Traceroute;
    use RRDs;
    
    
    $cgi = new CGI; 

#    print $cgi->header(
#    -type  =>  'text/html',
#    -cost  =>  'Three smackers',
#    -annoyance_level => 'high',
#    -complaints_to   => 'bit bucket'
#    );
#   print  $cgi->start_html(); 
    
     $kod=$cgi->param('CODE');
    $USER=$cgi->param('USER');
    $PASS=$cgi->param('PASS');

    #wlacza/wylacz autoryzacje komentujac linie nizej
    
    if (defined($kod)){

    if (defined($USER) && defined ($PASS) && ($USER eq "admin") && ($PASS eq "abc123"))    {
#if (defined($USER) && defined ($PASS) &&     
    
#====================================================================
    #0
    #TEST
    if ($kod eq "0") {
    print "OK";
    }

#====================================================================
    
    #11
    #PING
    #wysyla ping dla argumentu ADR i zwraca czas odpowiedzi
     if ($kod eq "11") {
    $host=$cgi->param('URL');
    $p = Net::Ping->new();
    $p->hires();
    ($ret, $duration, $ip) = $p->ping($host, 5.5);
    if ($ret) {
    printf("$host [ip: $ip] odpowiada (czas odp.: %.2f ms)\n", 1000 * $duration);
    } else
    {
    printf "$host nie odpowiada";
    } 
#wersja konsolowa
#         $abc=$cgi->param('ADR');
#         $b=`/usr/bin/sudo /bin/ping $abc -c 1`;
#         print  $b;
     }
     
#====================================================================
    #12
    #HOST
    #okresla adres ip na podstawie url'a
    if ($kod eq "12") {
    $host=$cgi->param('URL');
    $a=`/usr/bin/host $host`;
    print $a;
    }
#====================================================================
    #13
    #TRACEROUTE
    #uruchamia tracerout'a dla ADR i zwraca wyjscie
     if ($kod eq "13") {
     
#      $host = $cgi->param('ADR');
#    $tr = Net::Traceroute->new(host=> $host);
#    if($tr->found) {
#        my $hops = $tr->hops;
#        if($hops > 1) {
#            print "Router was " .
#                $tr->hop_query_host($tr->hops - 1, 0) . "\n";
#        }
#    }

         $abc=$cgi->param('URL');
         $b=`/usr/bin/sudo /usr/bin/tracert $abc `;
         print $b;
     }

#====================================================================
    #14 
    #ARPSCAN
    #uruchamia arpscan i zwraca wyjscie
      if ($kod eq "14") {
        $IF = $cgi->param('IF');
         $b=`/usr/bin/sudo /usr/sbin/arpscan $IF`;
         print $b;       
     }
     
#====================================================================
    #15
    #ARPWATCH
    #wysyla informacje zebrane przez arpwatchd
      if ($kod eq "15") {
         $a =  `/usr/bin/sudo /bin/cat /var/lib/arpwatch/arp.dat`;      
         print $a; 
     }     

#====================================================================
    #16
    #NBTSCAN
    #wysyla informacje z nbtscan
      if ($kod eq "16") {
        $NET = $cgi->param('NET');
         $a =  `/usr/bin/sudo /usr/bin/nbtscan -s ' ' $NET`;      
         print $a; 
     }     

#====================================================================
    #17
    #IFCONFIG GET
    #wysyla ip maske i broadcast danego interfejsu
      if ($kod eq "17") {
        $IF = $cgi->param('IF');
         $a =  `/usr/bin/sudo /sbin/ifconfig $IF |grep inet`;      
         print $a; 
     }     

#====================================================================
    #18
    #IFCONFIG GET ALL
    #wysyla ip maske i broadcast wszystkich interfejsow
      if ($kod eq "18") {
         $a = `/usr/bin/sudo /sbin/ifconfig`;      
         #$a = `/usr/bin/sudo /bin/cat /tmp/if `;
         print "\n$a"; 
     }     

#====================================================================
    #19
    #IFCONFIG SET
    #ustawia ip maske i broadcast danego interfejsu
      if ($kod eq "19") {
        $C = $cgi->param('C');
        #$IF = $cgi->param('IF');
        #$IP = $cgi->param('IP');
        #$MASK = $cgi->param('MASK');
        #$BCAST = $cgi->param('BCAST');
        
         $a =  `/usr/bin/sudo /sbin/ifconfigx $C 2> /tmp/x`;      
         $b = `/bin/cat /tmp/x`;
         print $b; 
     }     
#====================================================================
    #31
    #REBOOT
    #resetuje serwer
      if ($kod  eq "31") {
         print  "OK";       
#        `/usr/bin/sudo reboot`;
     }     

#====================================================================     
    #32
    #WoL
    #wywoluje metode WakeOnLan z biblioteki perla z podanymi argumentami
      if ($kod eq "32") {
         $host = $cgi->param('HOST');
         $mac = $cgi->param('MAC');
         $port = $cgi->param('PORT');
         Net::Wake::by_udp($host,$mac,$port );
         print "Wyslano Magic Packet";       
     }

#====================================================================     
    #33
    #INTERFEJSY
    #zwraca dostepne interfejsy sieciowe
     if ($kod eq "33"){
    @all_ifs = Net::Interface->interfaces();
    @ifnames     = "@all_ifs";
    print @ifnames
     }

#====================================================================         
}     else{
     print "44 Brak autoryzacji";
}
    } 
     else {
        print "500 Zdeformowane zadanie";              
     }
    
#    print $cgi->end_html;
              
     
 