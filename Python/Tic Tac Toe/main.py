# Author: Zeyad Mohamed Soliman
# Title: Tic Tac Toe text based game

first_row_symbols = ['-', '-', '-']
second_row_symbols = ['-', '-', '-']
third_row_symbols = ['-', '-', '-']

game_on = True
x_turn = True
o_turn = False


# Function to display the board in the needed format
def print_board(first_row, second_row, third_row):
    print('  1 2 3')
    print('1 ' + '|'.join(first_row))
    print('2 ' + '|'.join(second_row))
    print('3 ' + '|'.join(third_row))


# Function to check the winner
def check_winner(first_row, second_row, third_row):
    # To compare the elements in first row
    if first_row[0] == first_row[1] == first_row[2] and first_row[0] != '-':
        return False

    # To compare the elements in second row
    if second_row[0] == second_row[1] == second_row[2] and second_row[0] != '-':
        return False

    # To compare the elements in third row
    if third_row[0] == third_row[1] == third_row[2] and third_row[0] != '-':
        return False

    # To compare the elements in each column
    for index in range(0, len(first_row)):
        if first_row[index] == second_row[index] == third_row[index] and first_row[index] != '-':
            return False

    # To compare the diagonals
    if first_row[0] == second_row[1] == third_row[2] and first_row[0] != '-':
        return False
    if first_row[2] == second_row[1] == third_row[0] and first_row[2] != '-':
        return False

    return True


print('Welcome to Tic Tac Toe game')
print_board(first_row_symbols, second_row_symbols, third_row_symbols)

while game_on:
    if x_turn:
        x_user_position = input('X to play, choose your position: ')
        x_user_position = x_user_position.split(' ')
        row = int(x_user_position[0])
        column = int(x_user_position[1])

        if row == 1:
            if first_row_symbols[column-1] == '-':
                first_row_symbols[column-1] = 'x'
            else:
                print('Cannot play here, choose another position')

                while first_row_symbols[column-1] == 'x' or first_row_symbols[column-1] == 'o':
                    x_user_position = input('X to play, choose your position: ')
                    x_user_position = x_user_position.split(' ')
                    row = int(x_user_position[0])
                    column = int(x_user_position[1])

                    if row == 2 or row == 3:
                        break

                if row == 2 :
                    second_row_symbols[column-1] = 'x'
                elif row == 3:
                    third_row_symbols[column-1] = 'x'
                else:
                    first_row_symbols[column-1] = 'x'

        elif row == 2:
            if second_row_symbols[column-1] == '-':
                second_row_symbols[column-1] = 'x'
            else:
                print('Cannot play here, choose another position')

                while second_row_symbols[column-1] == 'x' or second_row_symbols[column-1] == 'o':
                    x_user_position = input('X to play, choose your position: ')
                    x_user_position = x_user_position.split(' ')
                    row = int(x_user_position[0])
                    column = int(x_user_position[1])

                    if row == 1 or row ==3 :
                        break

                if row == 1 :
                    first_row_symbols[column-1] = 'x'
                elif row == 3:
                    third_row_symbols[column-1] = 'x'
                else:
                    second_row_symbols[column-1] = 'x'

        elif row == 3:
            if third_row_symbols[column-1] == '-':
                third_row_symbols[column-1] = 'x'
            else:
                print('Cannot play here, choose another position')

                while third_row_symbols[column-1] == 'x' or third_row_symbols[column-1] == 'o':
                    x_user_position = input('X to play, choose your position: ')
                    x_user_position = x_user_position.split(' ')
                    row = int(x_user_position[0])
                    column = int(x_user_position[1])

                    if row == 1 or row == 2:
                        break

                if row == 1 :
                    first_row_symbols[column-1] = 'x'
                elif row == 2 :
                    second_row_symbols[column-1] = 'x'
                else:
                    third_row_symbols[column-1] = 'x'

        print_board(first_row_symbols, second_row_symbols, third_row_symbols)

        x_turn = False
        o_turn = True
        game_on = check_winner(first_row_symbols, second_row_symbols, third_row_symbols)

        if game_on == False:
            print('X wins, game over')
            break

    elif o_turn:
        o_user_position = input('O to play, choose your position: ')
        o_user_position = o_user_position.split(' ')
        row = int(o_user_position[0])
        column = int(o_user_position[1])

        if row == 1:
            if first_row_symbols[column - 1] == '-':
                first_row_symbols[column - 1] = 'o'
            else:
                print('Cannot play here, choose another position')

                while first_row_symbols[column - 1] == 'x' or first_row_symbols[column - 1] == 'o':
                    o_user_position = input('O to play, choose your position: ')
                    o_user_position = o_user_position.split(' ')
                    row = int(o_user_position[0])
                    column = int(o_user_position[1])

                    if row == 2 or row == 3:
                        break

                if row == 2:
                    second_row_symbols[column - 1] = 'o'
                elif row == 3:
                    third_row_symbols[column - 1] = 'o'
                else:
                    first_row_symbols[column - 1] = 'o'

        elif row == 2:
            if second_row_symbols[column - 1] == '-':
                second_row_symbols[column - 1] = 'o'
            else:
                print('Cannot play here, choose another position')

                while second_row_symbols[column - 1] == 'x' or second_row_symbols[column - 1] == 'o':
                    o_user_position = input('O to play, choose your position: ')
                    o_user_position = o_user_position.split(' ')
                    row = int(o_user_position[0])
                    column = int(o_user_position[1])

                    if row == 1 or row == 3:
                        break

                if row == 1:
                    first_row_symbols[column - 1] = 'o'
                elif row == 3:
                    third_row_symbols[column - 1] = 'o'
                else:
                    second_row_symbols[column - 1] = 'o'

        elif row == 3:
            if third_row_symbols[column - 1] == '-':
                third_row_symbols[column - 1] = 'o'
            else:
                print('Cannot play here, choose another position')

                while third_row_symbols[column - 1] == 'x' or third_row_symbols[column - 1] == 'o':
                    o_user_position = input('O to play, choose your position: ')
                    o_user_position = o_user_position.split(' ')
                    row = int(o_user_position[0])
                    column = int(o_user_position[1])

                    if row == 1 or row == 2:
                        break

                if row == 1:
                    first_row_symbols[column - 1] = 'o'
                elif row == 2:
                    second_row_symbols[column - 1] = 'o'
                else:
                    third_row_symbols[column - 1] = 'o'

        print_board(first_row_symbols, second_row_symbols, third_row_symbols)

        x_turn = True
        o_turn = False
        game_on = check_winner(first_row_symbols, second_row_symbols, third_row_symbols)

        if game_on == False:
            print('O wins, game over')
            break

    if '-' not in first_row_symbols and '-' not in second_row_symbols and '-' not in third_row_symbols:
        print('Draw, game over')
        game_on = False

