from turtle import Turtle
STARTING_POSITION = (0, -280)
MOVE_DISTANCE = 10
FINISH_LINE_Y = 280


class Player(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("turtle")
        self.penup()
        self.reset_turtle()
        self.setheading(90)

    def move(self):
        self.fd(MOVE_DISTANCE)

    def reset_turtle(self):
        self.goto(STARTING_POSITION)

    def at_finish_line(self):
        if self.ycor() >= FINISH_LINE_Y:
            return True
