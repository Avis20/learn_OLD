#!/usr/local/bin/perl

use strict;
#use warnings;

#use LWP::Debug qw(+);
use LWP::UserAgent;
use HTTP::Cookies;
#use Encode qw/decode/;
use Encode qw/encode decode/;
use Data::Dumper;

my @success_proxies = ();
my @good_proxies = ();
my @proxy_list = qw(78.26.170.184:8080
213.149.188.243:8080
213.1.255.42:8080
91.238.28.101:8080
183.88.53.148:8080
78.25.98.114:8080
81.24.85.158:41258
187.95.128.83:20183
175.181.40.61:8080
43.229.76.222:8888
187.5.218.215:20183
94.141.156.105:41258
181.176.209.86:8080
177.36.131.200:20183
5.189.135.153:8888
191.34.162.234:8080
37.230.114.6:3128
158.69.150.164:8080
125.212.203.161:80
195.208.172.70:8080
36.37.134.18:80
206.81.5.117:3128
80.211.169.186:80
5.189.162.175:3128
185.233.176.150:8080
);

my $url = 'http://officedepot.com';
my @set_cookie;

for (my $count = 0; $count <= $#proxy_list; $count++) {
 	print $proxy_list[$count] . " ";
 	my $ua = LWP::UserAgent->new;
 	$ua->proxy( 'http', "http://" . $proxy_list[$count] );

 	#my $cookie_jar = HTTP::Cookies->new();
 	
        #print $cookie_jar->as_string;
        $ua->default_header("Connection" => "keep-alive");
        $ua->default_header("Accept" => "text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5");
        $ua->default_header("Accept-Language" => "en-US,en;q=0.8");
        $ua->default_header("Accept-Charset" => "ISO-8859-1,utf-8;q=0.7,*;q=0.3");
        #$ua->default_header("Cookie" => "GEO_STATE=CA; GEO_CITY=SANDIEGO; GEO_POSTAL=92101; op1587http___www_officedep_6gum=a01702d03o28a4q08l31u6665; op1587http___www_officedep_6liid=a01702d03o28a4q08l31u6665; opBannerClicked=no; cmTPSet=Y; invited_visitor_814=1; JSESSIONID=0000wXEGIhs0xhXnosbX0TbWt2W:13ddprb4e; jsession_unique_id=1349378501411; CU_BRAND=OD; IBSD_LOCALE=en_US; CID_CART_COOKIE=fYr_vup8jRtef4ydMz7e3J3; ODCSASF=y; usy46gabsosd=ODCSA__-4_1349378502494_3670; atgPlatoStop=1; fs_nocache_guid=A9A78BE662FD4938D1AA82882EECA966; IS3_GSV=DPL-0_TES-1349378503_PCT-1349378503_GeoIP-*_GeoCo-_GeoRg-_GeoCt-_GeoNs-_GeoDm-; IS3_History=1349376269-1-62_1--1+5--1+7--1__1-5-7_; CoreAt=90031492=1|2|0|0|0|0|0|0|0|0|0|1|1|1349374209||&");
        $ua->agent("Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.6 (KHTML, like Gecko) Chrome/20.0.1092.0 Safari/536.6");
        #BrontesaurusUserAgent
        #$ua->agent($BrontesaurusUserAgent2);
        #$ua->cookie_jar($cookie_jar);
        $ua->timeout(100);
 	my $response = $ua->get($url);
 	print $response->status_line . "\n";
        if ($response->is_success) {
                open (SUCCESSFILE, '>>success.txt'); 	        
                print SUCCESSFILE $proxy_list[$count] . "\n";
                close (SUCCESSFILE);
        } elsif($response->status_line =~ /403/) {
                open (GOODFILE, '>>good.txt'); 	        
                print GOODFILE $proxy_list[$count] . "\n";
                close (GOODFILE);
        } else {
                open (BADFILE, '>>bad.txt'); 	        
                print BADFILE $proxy_list[$count] . "\n";
                close (BADFILE);
        }	
 	
 }


