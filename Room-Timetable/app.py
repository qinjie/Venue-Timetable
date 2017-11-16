import json

import pymysql
from chalice import Chalice

db_host = "ec2-13-228-113-29.ap-southeast-1.compute.amazonaws.com"
db_name = "room_timetable"
db_username = "ecer"
db_password = "Soe7014Ece"


app = Chalice(app_name="room_timetable")


@app.route("/venue/{venue_name}/date/{date}")
def index(venue_name, date):
    result = []
    try:
        conn = pymysql.connect(db_host, user=db_username, passwd=db_password, db=db_name, connect_timeout=5)
    except Exception as e:
        conn = pymysql.connect()
        print ("ERROR: " + e)
    print("SUCCESS: Connection to RDS mysql instance succeeded")
    with conn.cursor() as cur:
        cur.execute("select subject_area, catalog_number, class_section, \
                    start_time, end_time, lesson_date.ldate, venue.name, lecturer.name \
                    from lesson left join lesson_date on lesson.id = lesson_date.lesson_id \
                    left join venue on lesson.venue_id = venue.id\
                    left join lesson_lecturer on lesson.id = lesson_lecturer.lesson_id\
                    left join lecturer on lesson_lecturer.lecturer_id = lecturer.id\
                    where location = '{}' and ldate= '{}'".format(venue_name,date))
    for row in cur:
        result.append({'subject_area':row[0],'catalog': row[1],'class': row[2],'start_time':str(row[3]), 'end_time':str(row[4]), 'date':str(row[5]), 'venue_name':row[6],'lecturer':row[7]})
    return json.dumps(result)