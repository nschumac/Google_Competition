#!/usr/bin/python3

import sys
import os
import shutil

def main():
    sys.path.append(os.path.realpath('..'))
    if sys.argv.__len__() != 4:
        sys.stdout = sys.stderr
        print("Usage: <year> <round> <amount>")
        sys.exit(1)
    else:
        os.path.dirname(os.path.abspath(__file__))
        path = ""
        path += "./"
        path += sys.argv[1]
        path += "/round_"
        path += sys.argv[2]
        if os.path.exists(path):
            sys.stdout = sys.stderr
            print("clear directory before you execute")
            sys.exit(1)
        else:
            os.mkdir(path)
            path += "/"
            for i in range (int(sys.argv[3])):
                newfile = open(path + str(chr(65 + i)) + ".cpp", 'w')
                shutil.copy("./default.cpp", path + str(chr(65 + i)) + ".cpp")
    
if __name__ == "__main__":
    main()




