"""
Created by: James Couse
Created on: nov 24 2023
Module uses an ultrasonic distance sensor to detect
whether a servo should be turned or not.
"""

import time
import board
from analogio import AnalogIn
import pwmio
from adafruit_motor import servo

potentiometer = AnalogIn(board.A2)
pwm = pwmio.PWMOut(board.A1, frequency=50)
ServoNumber1 = servo.Servo(pwm)
map = 66000 / 180

while True:
    print ((potentiometer.value / map))
    ServoNumber1.angle = potentiometer.value / map
    time.sleep(0.05)