import serial
import pandas as pd
import joblib

model=joblib.load('logistic_regression_model.pkl')
ser=serial.Serial('COM6',9600)
while True:
    data=ser.readline().decode().strip()
    print(data)
    temp, humidity, soil_moisture = map(int,data.split(','))

    new_data={
        'temp':temp,

        'humidity':humidity,
        'soil_moisture':soil_moisture
    }

    new_data_df=pd.DataFrame([new_data])

    prediction=model.predict(new_data_df)

    if prediction[0]==0:
        print("pump is off")
        ser.write(b'0')
    else:
        print("pump is on")
        ser.write(b'1')

