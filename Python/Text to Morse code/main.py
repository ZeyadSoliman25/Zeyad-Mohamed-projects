# Author: Zeyad Mohamed Soliman
# Title: Text to Morse code program

MORSE_CODE_LETTERS = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....',
    'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.',
    'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
    'Y': '-.--', 'Z': '--..',
    '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...',
    '8': '---..', '9': '----.', '0': '-----',
    '.': '.-.-.-', ',': '--..--', '?': '..--..', "'": '.----.', '!': '-.-.--', '/': '-..-.', '(': '-.--.',
    ')': '-.--.-', '&': '.-...', ':': '---...', ';': '-.-.-.', '=': '-...-', '+': '.-.-.', '-': '-....-',
    '_': '..--.-', '"': '.-..-.', '$': '...-..-', '@': '.--.-.', ' ': '_'
}

program_on = True  # to control the flow of the program

print('Welcome to the Morse code cipher program')

while program_on:
    converted_message = []
    user_message = input('Enter your message: ').upper()

    for index in range(0, len(user_message)):
        for char in MORSE_CODE_LETTERS.keys():
            if user_message[index] == char:
                converted_message.append(MORSE_CODE_LETTERS[char])

    print(f'Your message is {user_message} \n')
    print(f'The converted message is {"".join(converted_message)}')

    program_continue = input('Do you want to continue Y for yes or Enter any letter to end program? ')

    if program_continue == 'Y':
        continue
    else:
        break

print('Nice Having you sir')

