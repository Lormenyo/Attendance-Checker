from flask import Flask, render_template, url_for
import pyrebase

app = Flask(__name__)

#  Initialize Firebase
config = {
    "apiKey": "AIzaSyAuU5WYHLP-TFiM5_0Yd0F1bj-bQb2JRLQ",
    "authDomain": "attendance-checker-ec526.firebaseapp.com",
    "databaseURL": "https://attendance-checker-ec526.firebaseio.com",
    "projectId": "attendance-checker-ec526",
    "storageBucket": "attendance-checker-ec526.appspot.com",
    "messagingSenderId": "98126431251",
    "serviceAccount": "C:/Users/Hannah/Desktop/rfid/attendance-checker-ec526-firebase-adminsdk-wi19i-ff6ce018a8.json"
  }

firebase = pyrebase.initialize_app(config)

db = firebase.database()

@app.route('/')
def admin():
    attendance = db.child("Attendance-Record").get()
    return render_template("tables.html", attendance=attendance)

    
if __name__ == '__main__':
    app.run(debug=True)