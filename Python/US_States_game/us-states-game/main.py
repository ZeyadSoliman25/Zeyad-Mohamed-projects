import turtle
import pandas

screen = turtle.Screen()
screen.title("U.S-States-game")
screen.setup(width=700, height=500)
image = "blank_states_img.gif"
screen.addshape(image)
turtle.shape(image)
data = pandas.read_csv("50_states.csv")
states = data["state"].to_list()
coordinates_x = data["x"].to_list()
coordinates_y = data["y"].to_list()
guessed_states = []
while len(guessed_states) < 50:
    user_answer = turtle\
        .textinput(title=f"score:{len(guessed_states)}/{50},Guess state", prompt="Guess a state's name?").title()
    if user_answer == "Exit":
        break
    for state in states:
        for guessed_state in guessed_states:
            if user_answer == guessed_state:
                user_answer = turtle \
                    .textinput(title=f"score:{len(guessed_states)}/{50},Guess state", prompt="Guess a state's name?")\
                    .title()
        if user_answer == state:
            position = states.index(state)
            sofia = turtle.Turtle()
            sofia.penup()
            sofia.hideturtle()
            sofia.goto(x=coordinates_x[position], y=coordinates_y[position])
            sofia.write(arg=f"{user_answer}", align="center", font=("courier", 10, "normal"))
            guessed_states.append(user_answer)

not_guessed_states = [state for state in states if state not in guessed_states]
missing_states = pandas.DataFrame(not_guessed_states)
missing_states.to_csv("Missing states")
