#!/usr/bin/env python

import os
import sys
import subprocess

if __name__ == "__main__":
    input_file = "./main.cpp"
    if len(sys.argv) > 1:
        input_file = sys.argv[1]
    basename = os.path.basename(input_file)
    filename = os.path.splitext(basename)[0]

    command = ["g++", input_file, "-o", filename]
    # error = os.system(" ".join(command))
    error = subprocess.call(command)

    if not error:
        print("Compile Success!")
        command = [os.path.realpath(".".join([filename, "exe"]))]
        subprocess.run(command)
    else:
        print("Compile Failed!")
