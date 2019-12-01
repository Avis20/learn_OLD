#!/usr/local/env perl

use uni::perl       qw| :dumper |;
use DBI;

my $dbh = DBI->connect(
    # 'dbi:Pg:dbname=fonmix_qa;host=localhost;port=5432', 'postgres', 1234
    'dbi:Pg:dbname=test_db;host=tsdb-2468e8cb-orlov-a36f.a.timescaledb.io;port=26913', 'tsdbadmin', 'ai73v2ey3mqtgmwh'
);

foreach my $date (1..9){

    my $date_start = '2019-0'.$date.'-01';
    my $date_end = '2019-0'.($date+1).'-01';

    my $sql = "
insert into stat.audios (audio_id, filial_id, ts_playing, count_chunks, is_announce, list_stat_files, is_ts_playing_corrected, content_subtype_id)
select
    uuid_in(md5(random()::text || clock_timestamp()::text)::cstring) as audio_id,
    round( random() * 300 ) as filial_id,
    timestamp '".$date_start."T00:00:00' + random() * (timestamp '".$date_start."T00:00:00' - timestamp '".$date_end."T00:00:00') as ts_playing,
    round( random() * 50 ) as count_chunks,
    (case when random() > 0.4 THEN true else false end) as is_announce,
    ARRAY[10000, 10000, 10000, 10000] as list_stat_files,
    (case when random() > 0.4 THEN true else false end) as is_ts_playing_corrected,
    round( random() * 10 ) as content_subtype_id
from generate_series(0, ?);
    ";

    foreach my $count (1..10){
        my $row = 10_000 * $count;
        my $start = time;
        warn "date = $date_start, row = $row; time start = ".localtime($start)."\n";
        my $sth = $dbh->prepare($sql);
        $sth->execute($row);
        $sth->finish;
        my $end = time();
        warn "time end ".localtime($end)."; duration = ".($end - $start)."\n";
    }
}

exit;