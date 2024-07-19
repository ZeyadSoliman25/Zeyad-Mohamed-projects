import art
print(art.logo)
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
ans = "yes"


def caesar(message,shift_amount,direction_message):
  delivered_message = ""
  if direction_message == "decode":
    shift_amount *= -1
  for letter in message:
    if letter in alphabet:
      if direction_message=="decode":
        position = alphabet.index(letter)+26
      position = alphabet.index(letter)
      new_position = position + shift_amount
      delivered_message += alphabet[new_position]
    else:
      delivered_message+= letter
  print(f"The {direction_message}d message is {delivered_message}")

while ans=="yes":
  direction = input("Type 'encode' to encrypt, type 'decode' to decrypt:\n")
  text = input("Type your message:\n").lower()
  shift = int(input("Type the shift number:\n"))
  if shift > 52 :
    shift= shift%26
  caesar(message=text,shift_amount=shift,direction_message=direction)
  ans=input("Do you want to continue? yes or no? \n")
else:
  print("Caesar saluts you!")