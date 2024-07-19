import tkinter


def kilometers_converter():
    miles = float(number_entry.get())
    kilometers = round(miles * 1.609, 1)
    kilometers_label.config(text=f"{kilometers} kilometers")


my_window = tkinter.Tk()
my_window.title("Units converter")
my_window.minsize(width=300, height=100)
my_window.config(padx=25, pady=25)

number_entry = tkinter.Entry()
number_entry.config(width=10)
number_entry.grid(column=2, row=0)

miles_label = tkinter.Label()
miles_label.config(text="Miles is equal to")
miles_label.grid(column=3, row=0)

kilometers_label = tkinter.Label()
kilometers_label.config(text=f"{0} kilometers")
kilometers_label.grid(column=2, row=1)

calculate_button = tkinter.Button(text="calculate", command=kilometers_converter)
calculate_button.grid(column=2, row=2)

my_window.mainloop()
