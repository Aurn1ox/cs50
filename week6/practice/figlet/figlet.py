#!/usr/bin/env python3

from pyfiglet import Figlet
import random
import sys

argc: int = len(sys.argv)

if argc != 1 and argc != 3:
    print("Invalid Usage")
    sys.exit(1)

figlet: Figlet = Figlet()

# get list of fonts
fonts: list[str] = figlet.getFonts()

# set random font
random_int: int = random.randint(0, len(fonts))
figlet.setFont(font=fonts[random_int])

if argc == 3:
    # check if argument is valid
    if sys.argv[1].lower() != '-f' and sys.argv[1].lower() != '--font':
        print("Invalid Usage")
        sys.exit(1)

    font: str = sys.argv[2].lower()

    # check if font is valid
    if font not in fonts:
        print("Invalid Usage")
        sys.exit(1)

    # set font
    figlet.setFont(font=font)


word: str = input("Input: ")
print(figlet.renderText(word))
