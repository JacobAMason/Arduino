import logging
from threading import Thread
import serial

__author__ = 'JacobAMason'


class ArduinoComm(Thread):
    def __init__(self, comPort="com10", baudrate=9600):
        logging.debug("Creating Thread")
        super().__init__(name="ArduinoComm")
        self.s = serial.Serial(comPort, baudrate)

    def readline(self):
        return self.s.readline().decode()

    def run(self):
        logging.debug("Listening for serial traffic")
        while 1:
            print(self.readline(), end="")

    def send(self, line):
        line = line.rstrip("\r\n")
        return self.s.write(line.encode())