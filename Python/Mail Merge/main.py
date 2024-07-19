with open("input/letters/starting_letter.txt") as mail:
    contents = mail.readlines()
    print(contents)

with open("input/names/invited_names.txt") as guest_list:
    names = guest_list.readlines()
    y = 0
    for i in names:
        x = i.strip()
        names[y] = x
        y += 1
    print(names)

for name in names:
    contents[0] = f"Dear {name},\n"
    print(contents)
    with open(f"output/ReadyToSend/{name}_invitation.txt", mode="w") as new_message:
        for line in contents:
            new_message.write(f"{line}")
