#define BLYNK_TEMPLATE_ID "TMPL3BMNG57pf"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "otE_0FGRYDyOoTOtReVRGlx3FSa2BFtA"
#define WIFI_SSID "srujan"
#define WIFI_PASS "11111111"


import serial
import requests

# Your Blynk Auth Token
auth_token = "your auth code"

ser = serial.Serial('COM3', 9600)

while True:
    data = ser.readline().decode().strip()
    print(data)
    temp, humidity, soil_moisture = map(int, data.split(','))

    # Create URL to send data to Blynk
    blynk_url = f"https://blynk-cloud.com/{auth_token}/update/"

    # Send temperature to V0, humidity to V1, and soil moisture to V2
    requests.get(f"{blynk_url}V0?value={temp}")
    requests.get(f"{blynk_url}V1?value={humidity}")
    requests.get(f"{blynk_url}V2?value={soil_moisture}")
