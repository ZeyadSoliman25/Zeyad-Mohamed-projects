import time
from turtle import Screen
from player import Player
from car_manager import CarManager
from scoreboard import Scoreboard

screen = Screen()
screen.setup(width=600, height=600)
screen.title("The turtle crossing game")
screen.tracer(0)
screen.listen()

sonia = Player()
car_manager = CarManager()
score_board = Scoreboard()

screen.onkey(key="Up", fun=sonia.move)
game_is_on = True

while game_is_on:
    time.sleep(0.1)
    car_manager.create_car()
    car_manager.move_cars()
    if sonia.at_finish_line():
        sonia.reset_turtle()
        score_board.increase_level()
        car_manager.increase_speed()

    for car in car_manager.all_cars:
        if car.distance(sonia) < 20:
            game_is_on = False
            score_board.game_over()

    screen.update()

screen.exitonclick()
