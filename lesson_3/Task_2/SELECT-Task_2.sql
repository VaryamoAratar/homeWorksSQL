select track_name, lenght_track
from track
where lenght_track >= (select max(lenght_track) from track) ;

select track_name, lenght_track
from track
where lenght_track >= '03:30:00' ;

select collection_name , collection_date
from collection
where collection_date between '2018-01-01' and '2020-01-01';

select first_name 
from musician 
where last_name is null;

select track_name 
from track
where (track_name like '%my%' or track_name like '%мой%') 
	or (track_name like '%My%' or track_name like '%Мой%');