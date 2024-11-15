from interpolation import interpolate_np, interpolate
import serial 
import time

def send_serial(data_str):
    # Sesuaikan parameter berikut
    port='COM5'

    baudrate=9600
    # Buka Serial port
    with serial.Serial(port, baudrate) as ser:
        # Kirim data
        while(True):
            ser.write(data_str.encode())
            time.sleep(1)

def main():
    while True:

        angle1 = float(input("Masukkan Sudut 1 (dalam derajat): "))
        angle2 = float(input("Masukkan Sudut 2 (dalam derajat): "))

        angles = [angle1, angle2]

        digital_units = interpolate_np(angles)
        encoded_str = ' '.join(digital_units.astype(str))

        # Kirim data
        print(encoded_str)
        send_serial(encoded_str)
 
        formatted_units = ' '.join(f'{value:04d}' for value in digital_units)
        send_serial(formatted_units)

if __name__ == '__main__': 
    main()
