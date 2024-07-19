import random
from art import logo
first_answer=input("Do you want to play a game of Blackjack? type 'y' to play or 'n'to exit. ")
player_current_score=0
computer_current_score=0
while first_answer=="y":
  print(logo)
  cards = [11,2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
  player_cards=[]
  computer_cards=[]
  should_continue=True
  should_continue_2=True 
  def draw_card_player(cards):
    player_cards.append(random.choice(cards))
  def draw_card_computer(cards):
    computer_cards.append(random.choice(cards))
  def calculate_score_player(player_cards):
    if sum(player_cards)>21 and player_cards.count(11)>0:
      player_cards.remove(11)
      player_cards.append(1)
    if sum(player_cards)==21:
      return 0 
    return sum(player_cards)
  def calculate_score_computer(computer_cards):
    if sum(computer_cards)>21 and computer_cards.count(11)>0:
      computer_cards.remove(11)
      computer_cards.append(1)
    if sum(computer_cards)==21:
      return 0
    return sum(computer_cards)
  def compare(player_current_score,computer_current_score):
    if player_current_score==computer_current_score:
      return 2
    elif player_current_score>computer_current_score and player_current_score>21:
      return 3
    elif player_current_score<computer_current_score and computer_current_score>21:
      return 4
    elif player_current_score<computer_current_score and player_current_score==0:
      return 5 
    elif player_current_score>computer_current_score and computer_current_score==0:
      return 6
    elif player_current_score>computer_current_score:
      return 1
    elif player_current_score<computer_current_score:
      return 0
  
  draw_card_player(cards)
  draw_card_player(cards)
  draw_card_computer(cards)
  player_current_score=calculate_score_player(player_cards)
  computer_current_score=calculate_score_computer(computer_cards)
  if player_current_score==0:
    print(f"Your cards:{player_cards},current score={player_current_score}")
    print (f"Computer cards:{computer_cards},current score={computer_current_score}")
    print("You got a BLACKJACK,You win.")
  else:
    print(f"Your cards:{player_cards},current_score={player_current_score}")
    print (f"Computer cards:{computer_cards},current_score={computer_current_score}")
    sec_ans=input("Type 'y' tp get another card or 'n' to pass. ")
    while sec_ans=="y":
      while should_continue:
        draw_card_player(cards)
        player_current_score=calculate_score_player(player_cards)
        if player_current_score>21:
          should_continue=False 
          sec_ans="n"
          should_continue_2=False 
          print(f"Your cards:{player_cards},final score={player_current_score}")
          print(f"Computer cards:{computer_cards},final score={computer_current_score}")
          print("You went over,You lose")
        elif player_current_score==21:
          print(f"Your cards:{player_cards},current score={player_current_score}")
          print (f"Computer cards:{computer_cards},current score={computer_current_score}")
          print("You got a BLACKJACK,You win.")
          should_continue=False 
          sec_ans="n"
          should_continue_2=False 
        elif player_current_score<21:
          print(f"Your cards:{player_cards},current score={player_current_score}")
          print(f"Computer cards:{computer_cards},current score={computer_current_score}")
          sec_ans=input("Type 'y' tp get another card or 'n' to pass. ")
          if sec_ans=="n":
            should_continue=False 
    else :
      while should_continue_2:
        draw_card_computer(cards)
        computer_current_score=calculate_score_computer(computer_cards)
        if computer_current_score==0:
          print(f"Your cards:{player_cards},final score={player_current_score}")
          print (f"Computer cards:{computer_cards},final score={computer_current_score}")
          print("Opponent got a BLACKJACK,You lose.")
          should_continue_2=False 
        if computer_current_score>21:
          should_continue_2=False 
          print(f"Your cards:{player_cards},final score={player_current_score}")
          print(f"Computer cards:{computer_cards},final score={computer_current_score}")
          print("Opponent went over,You win.")
        if computer_current_score>17:
          should_continue_2= False
    winning=compare(player_current_score,computer_current_score)
    if winning == 0:
      print(f"Your cards:{player_cards},final score={player_current_score}")
      print (f"Computer cards:{computer_cards},final score={computer_current_score}")
      print("You lose.")
    elif winning== 1:
      print(f"Your cards:{player_cards},final score={player_current_score}")
      print (f"Computer cards:{computer_cards},final score={computer_current_score}")
      print("You win.")
    elif winning ==2 :
      print(f"Your cards:{player_cards},final score={player_current_score}")
      print (f"Computer cards:{computer_cards},final score={computer_current_score}")
      print("Push,It's a draw.")
    elif winning == 3 :
      print("Give me your money bunk!")
    elif winning == 4 :
      print("Here is your money champ!")
    elif winning ==5 :
      print("Congrats,Champ!")
    elif winning == 6:
      print("Better luck next time, looser!")
    
  first_answer=input("Do you want to play a game of Blackjack? type 'y' to play or 'n'to exit. ")
