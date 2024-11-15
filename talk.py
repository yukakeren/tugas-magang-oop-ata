import numpy as np

def interpolate(angle):
    # Pastikan sudut berada di dalam range
    if angle < -150.0: angle = -150.0
    elif angle > 150.0: angle = 150.0
    # Persamaan interpolasi linear dari range
    # [-150, 150] ke [0, 1023]
    digital_unit = (angle + 180) * 1023 / 360
    # Kembalikan nilai sebagai integer
    return int(digital_unit)

def interpolate_np(angles):
    angle_range=(-150.0, 150.0)
    digital_range=(0, 1023)
    digital_units = np.interp(angles,
    angle_range, digital_range)
    return digital_units.astype(int)

def main():
    # Sudut dalam derajat
    angles = [100.0, -90.0, 73.34]
    # Nilai digital dari sudut
    digital_units = [interpolate(angle) for angle in angles]
    # Tampilkan nilai sebelum dan setelah interpolasi
    print(f'Sudut: {angles}')
    print(f'Nilai: {digital_units}')
    digital_units_np = interpolate_np(angles)
    print(f'Nilai Numpy: {digital_units}')

if __name__ == '__main__':
    main()
