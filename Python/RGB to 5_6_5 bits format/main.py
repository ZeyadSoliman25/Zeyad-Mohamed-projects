NEW_RGB = input("Enter the list: ").split(',')
NEW_RGB =[int(i) for i in NEW_RGB ]

NEW_RGB_length = len(NEW_RGB)

RGB_5_6_5_format = []

i = 0

index = 0

while i < NEW_RGB_length-2:
    red = NEW_RGB[i]
    green = NEW_RGB[i+1]
    blue = NEW_RGB[i+2]

    red = round ((red * 31) / 255)
    green = round ((green * 63)/255)
    blue = round((blue * 31)/255)

    red_shifted = red << 11
    green_shifted = green << 5

    new_format = red_shifted | green_shifted | blue

    RGB_5_6_5_format.append(new_format)
    i += 3


with open ("test.txt", 'w') as my_file :
    i = 0
    for i in range(len(RGB_5_6_5_format)):
        my_file.write(hex(RGB_5_6_5_format[i]))
        my_file.write(',')


print(len(RGB_5_6_5_format))

