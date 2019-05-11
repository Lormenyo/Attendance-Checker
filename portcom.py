from time import sleep
import datetime
import serial
import pyrebase

ser = serial.Serial('COM10', 9600) # Establish the connection on a #specific port

#  Initialize Firebase
config = {
    "apiKey": "xxxxxxxxxxxxxxxxxx",
    "authDomain": "attendance-checker-ec526.firebaseapp.com",
    "databaseURL": "https://attendance-checker-ec526.firebaseio.com",
    "projectId": "attendance-checker-ec526",
    "storageBucket": "attendance-checker-ec526.appspot.com",
    "messagingSenderId": "xxxxxxxxxxxxx",
    "serviceAccount": "C:/Users/Hannah/Desktop/rfid/attendance-checker-ec526-firebase-adminsdk-wi19i-ff6ce018a8.json"
  }

firebase = pyrebase.initialize_app(config)

db = firebase.database()

records = {
    "30:81:E2:19": "Hannah Boadiwaa Lormenyo",
    "3D:49:40:C2": "Tito Effiong-Akpan"
}



counter = 32 # Below 32 everything in ASCII is gibberish
while True:
    counter +=1
    ser.write(str(chr(counter))) # Convert the decimal number to ASCII then send it to the Arduino
    line = ser.readline()  # Read the newest output from the Arduino
    print(line)
    k = line.replace('\x00','\n').rstrip('\r\n')
    # print(k)
    print(records)
    if k == '':
        pass
    else:
        db.child("Attendance-Record").push(
                                {"id": k,
                                "name": records[k],
                                "date": datetime.datetime.now().strftime("%d")+ " " + datetime.datetime.now().strftime("%B") + " " +            datetime.datetime.now().strftime("%Y"),
                                "time": datetime.datetime.now().strftime("%H")+ " :" + datetime.datetime.now().strftime("%M"  + " :" + datetime.datetime.now().strftime("%S"))})

        attendance_length = len(db.child("Attendance-Record").get().each())    
        ser.write(attendance_length)                 
        print(attendance_length)
    sleep(.1) # Delay for one tenth of a second
    if counter == 255:
        counter = 32
    
