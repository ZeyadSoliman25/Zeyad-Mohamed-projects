# Author: Zeyad Mohamed Soliman
# Tile: Typing speed test

from tkinter import *
from time import time


TEST_TEXT = ("The quick brown fox jumps over the lazy dog. "
             "This sentence contains all the letters of the alphabet"
             " and is often used for typing practice. "
             "Typing speed is measured in words per minute (WPM),"
             " which is the number of words you can type correctly in one minute. "
             "To improve your typing speed, practice regularly and focus on accuracy. "
             "Make sure to use all your fingers and maintain a proper posture while typing. "
             "Look at the screen, not at the keyboard, and try to type without looking at your hands."
             " Remember, consistency is key. Set a goal for yourself and track your progress over time. "
             "With patience and practice, you will see improvement in your typing speed and accuracy. Happy typing!")

FONT = ('Courier', 11)

called_before = False
time_called = 0


def check_text():
    global called_before
    global time_called

    if not called_before:
        called_before = True
        time_called = time()

    current_time = time()

    time_left.config(text=f"Time left = {round(60 - (current_time-time_called), 2)} secs")

    correct_words_score = 0
    text_words = text.get("1.0", END).split(' ')
    user_words = user_input.get("1.0", END).split(' ')

    for i, word in enumerate(user_words):
        if word == text_words[i]:
            correct_words_score += 1
        elif user_words[i] == '\n' or user_words[i] == ' ':
            break

    score.config(text=f"Correct words = {correct_words_score}", font=FONT)

    solver = window.after(100, check_text)

    if called_before:
        if current_time - time_called >= 60:
            window.after_cancel(solver)
            time_left.config(text="Time left = 0 secs")
            user_input.config(state=DISABLED)


window = Tk()
window.title("Typing speed test")
window.config(padx=20, pady=20)

canvas = Canvas(width=400, height=400, highlightthickness=0)
canvas.grid(row=0, column=0)

score = Label(text='Correct words = 0', font=FONT)
score.grid(row=0, column=0)

time_left = Label(text="Time left = 60 secs", font=FONT)
time_left.grid(row=1, column=0)

text = Text(window, wrap="word", font=FONT, fg="black", height=10, width=80)
text.insert("1.0", TEST_TEXT)
text.config(state=DISABLED)
text.grid(row=0, column=1)

user_input_frame = Frame(window, background="black", padx=2, pady=2)
user_input_frame.grid(row=1, column=1)
user_input = Text(user_input_frame, font=FONT, fg="black", height=10, width=80)
user_input.grid(row=1, column=1)

start_button = Button(text="Start", command=check_text, width=14)
start_button.grid(row=1, column=2)

window.mainloop()
