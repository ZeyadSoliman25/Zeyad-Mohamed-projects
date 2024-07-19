import pandas


data = pandas.read_csv("nato_phonetic_alphabet.csv")
nato_dic = {row.letter: row.code for (index, row) in data.iterrows()}
# print(nato_dic)

while True:
    user_word = input("Enter a word: ").upper()
    word = [word_letter for word_letter in user_word]
    try:
        word_nato = [nato_dic[letter] for letter in word]
    except KeyError:
        print("Sorry , only alphabet letters are allowed")
    else:
        break

print(word_nato)
