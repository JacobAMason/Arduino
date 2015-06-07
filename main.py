#!python3
import logging
from sys import stdin
from ArduinoComm import ArduinoComm

__author__ = 'JacobAMason'

logging.basicConfig(level=logging.DEBUG,
                    format="[%(levelname)s] (%(threadName)-10s) %(message)s")


if __name__ == "__main__":
    ac = ArduinoComm()
    ac.start()
    for line in stdin:
        ac.send(line)