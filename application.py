from flask import Flask, render_template
from flask_socketio import SocketIO, emit
import serial
import pandas as pd
import joblib
import threading
import time

app = Flask(__name__)
socketio = SocketIO(app)

model = joblib.load('logistic_regression_model.pkl')

ser = serial.Serial('COM3', 9600)

latest_data = {
    'temp': 0,
    'humidity': 0,
    'soil_moisture': 0,
    'pump_status': 'Off'
}

def read_sensor_data():
    global latest_data
    while True:
        try:
            data = ser.readline().decode().strip()
            temp, humidity, soil_moisture = map(int, data.split(','))

            new_data = {
                'temp': temp,
                'humidity': humidity,
                'soil_moisture': soil_moisture
            }

            new_data_df = pd.DataFrame([new_data])

            prediction = model.predict(new_data_df)

            if prediction[0] == 0:
                pump_status = "Off"
                ser.write(b'0')
            else:
                pump_status = "On"
                ser.write(b'1')

            # Update latest_data
            latest_data = {
                'temp': temp,
                'humidity': humidity,
                'soil_moisture': soil_moisture,
                'pump_status': pump_status
            }


            time.sleep(5)

        except Exception as e:
            print(f'Error: {str(e)}')

sensor_thread = threading.Thread(target=read_sensor_data)
sensor_thread.daemon = True
sensor_thread.start()

@app.route('/')
def index():
    return render_template('index.html')

@socketio.on('connect')
def handle_connect():
    emit('update_sensor_data', latest_data)

if __name__ == '__main__':
    socketio.run(app, debug=True)
