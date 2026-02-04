# Wearable Sensor-Based Physical Game Controller (Arduino)

This project implements a wearable, sensor-based physical game controller
that enables full-body interaction with a PC game using Arduino.

## Overview
- Arduino-based embedded system with USB HID keyboard emulation
- Pressure sensors for movement and jump detection
- PIR motion sensor for kick detection
- IR proximity sensor for punch detection
- Real-time thresholding and state-based input logic

## Hardware
- Arduino Leonardo
- Pressure sensors (foot-mounted)
- PIR motion sensor
- IR proximity sensor

## How It Works
Physical actions detected by the sensors are translated into keyboard inputs
using Arduino's Keyboard library, allowing the system to control a PC game
without additional software.

## Technologies
Arduino · Embedded Systems · USB HID · Sensors
