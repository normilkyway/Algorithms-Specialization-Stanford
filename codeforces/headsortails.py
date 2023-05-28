import random as r
import os
import time


def main():
    return ("Heads" if r.random() < 0.5 else "Tails")


def fmain():
    print("Head")


# fmain()
os.system(f"say tails")


def ffmain():
    while True:
        os.system("say say the question")
        time.sleep(10)
        for i in range(10, 0, -1):
            time.sleep(1)
            os.system(f"say {i}")
        if main():
            os.system("say say the answer")
        else:
            os.system("say no need to say the answer")
        input()
