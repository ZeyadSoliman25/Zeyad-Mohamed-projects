# Author: Zeyad Mohamed Soliman
# Title: Image Watermarking Desktop App

from tkinter import *
from tkinter import filedialog
import cv2

FONT = ('Courier', 14)


def get_image():
    file_path = filedialog.askopenfilename()
    image_path_box.insert(0, file_path)


def watermark_image():
    img_path = image_path_box.get()
    watermark = cv2.imread("right.png")
    img = cv2.imread(img_path)

    h_wm, w_wm, c_wm = watermark.shape
    h_img, w_img, _ = img.shape

    center_y = int(h_img/2)
    center_x = int(w_img/2)

    top_y = center_y - int(h_wm/2)
    bottom_y = top_y + h_wm
    left_x = center_x - int(w_wm/2)
    right_x = left_x + w_wm

    destination = img[top_y:bottom_y, left_x:right_x]
    result = cv2.addWeighted(destination, 0.8, watermark, 0.2, 0)
    img[top_y:bottom_y, left_x:right_x] = result
    cv2.imwrite("watermarked.png", img)


window = Tk()
window.title('Image Watermarking Desktop App')
window.config(pady=40, padx=60)

canvas = Canvas(width=400, height=400, highlightthickness=0)
logo = PhotoImage(file='logo.png')
canvas.create_image(200, 200, image=logo)
canvas.grid(row=0, column=1)

image_path = Label(text="Image:", font=FONT)
image_path.grid(row=1, column=0)

image_path_box = Entry(width=35)
image_path_box.focus()
image_path_box.grid(row=1, column=1, columnspan=2)

browse_button = Button(text="Browse", command=get_image, width=14)
browse_button.grid(row=1, column=3)

watermark_button = Button(text="Watermark image", command=watermark_image, width=14)
watermark_button.grid(row=1, column=4)

window.mainloop()
