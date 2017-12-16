import json
import datetime
from time import mktime
import pymysql
from chalice import Chalice

db_host = "iot-centre-rds.crqhd2o1amcg.ap-southeast-1.rds.amazonaws.com"
db_name = "room_timetable"
db_username = "root"
db_password = "Soe7014Ece"


app = Chalice(app_name="room_timetable")


@app.route("/venue/{venue_name}/date/{date}")
def index(venue_name, date):
    result = []
    conn = connect_database()
    with conn.cursor() as cur:
        cur.execute("select from_time, to_time, purpose, user.name, venue.name from booking \
                    join user on booking.user_id = user.id\
                    join venue on booking.venue_id = venue.id\
                    where location = '{}' and approval=1 and bdate='{}'".format(venue_name,date))
    for row in cur:
        result.append({'start_time':str(row[0]), 'end_time':str(row[1]), 'purpose':row[2],'user':row[3],'venue_name':row[4]})
    if result:
        return json.dumps(result)
    else:
        return 'Venue booking not found'

@app.route('/booking', methods=['POST'])
def booking():
    request = app.current_request
    data = request.json_body

    user_id = str(data['user_id'])
    venue_id = str(data['venue_id'])
    purpose = str(data['purpose'])
    bdate = str(data['bdate'])
    from_time = str(data['from_time'])
    to_time = str(data['to_time'])
    conn = connect_database()
    try:
        with conn.cursor() as cur:
            cur.execute('INSERT INTO `booking`(`user_id`, `venue_id`, `purpose`, `bdate`, `from_time`, `to_time`) VALUES (%s,%s,%s,%s,%s,%s)',(user_id, venue_id, purpose,bdate, from_time,to_time))
            conn.commit()
    except Exception as e:
        return 'Booking Fail: ' + e.message
    return 'Booking Success'

@app.route('/booking/cancel', methods=['POST'])
def canceling():
    request = app.current_request
    data = request.json_body

    user_id = str(data['user_id'])
    booking_id = str(data['booking_id'])
    conn = connect_database()

    isAdmin = False
    with conn.cursor() as cur:
        cur.execute('SELECT * FROM `user` where `id`=%s and `role`=20',(user_id))
    for row in cur:
        if row:
            isAdmin = True
            break

    if isAdmin:
        try:
            with conn.cursor() as cur:
                response = cur.execute('DELETE FROM `booking` WHERE `id`=%s', (booking_id))
                conn.commit()
        except Exception as e:
            return 'Admin Cancel Fail: ' + e.message
        if response == 0:
            return 'Admin Cancel Fail'
        return 'Admin Cancel Success'
    else:
        try:
            with conn.cursor() as cur:
                response = cur.execute('DELETE FROM `booking` WHERE `user_id` = %s and `id`=%s',(user_id, booking_id))
                conn.commit()
        except Exception as e:
            return 'Cancel Fail: ' + e.message
        if response == 0:
            return 'Cancel Fail'
        return 'Cancel Success'

def connect_database():
    try:
        conn = pymysql.connect(db_host, user=db_username, passwd=db_password, db=db_name, connect_timeout=5)
    except Exception as e:
        conn = pymysql.connect()
        print (e)
    print("SUCCESS: Connection to RDS mysql instance succeeded")
    return conn