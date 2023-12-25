#!/usr/bin/env python3

greeting = input("Greeting: ").strip().lower()

if greeting[0] == "h":
    if greeting[:5] == "hello":
        print("$0")
    else:
        print("$20")

else:
    print("$100")
