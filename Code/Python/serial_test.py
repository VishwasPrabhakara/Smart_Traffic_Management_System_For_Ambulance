import serial
import time

data = serial.Serial(
                  'COM6',
                  baudrate = 9600,
                  parity=serial.PARITY_NONE,
                  stopbits=serial.STOPBITS_ONE,
                  bytesize=serial.EIGHTBITS,                  
                  timeout=1
                  )

def send_data(a):
  data.write(str.encode(a))
  print('data sent......')
  
def read_data(a):
  d = data.readline()
  d = d.decode('UTF-8', 'ignore')
  if d:
    print(d)
    return d
