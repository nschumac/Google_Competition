#!/usr/bin/python3

import sys
import os
import shutil

def main():
	sys.path.append(os.path.realpath('..'))
	if sys.argv.__len__() != 5 and sys.argv.__len__() != 6:
		sys.stdout = sys.stderr
		print("Usage: <type k = Kickstart, c = Codejam> <year> <round> <amount> <optional -f for force>")
		sys.exit(1)
	else:
		os.path.dirname(os.path.abspath(__file__))
		path = ""
		path += "./"
		path += sys.argv[2]
		path +=  "/kickstart" if sys.argv[1] == "k" else "/codejam"
		path += "/round_"
		path += sys.argv[3]
		if not os.path.exists(path):
			try:
				os.makedirs(path)
				print("Created Directory!")
			except OSError as error:
				print(error)
		else:
			print("Directory Exits!")
		path += "/"
		for i in range (int(sys.argv[4])):
			newfile = path + str(chr(65 + i)) + ".cpp"
			if not os.path.exists(newfile) or (sys.argv.__len__() == 6 and sys.argv[5] == "-f"):
				shutil.copy("./default.cpp", newfile)
				print("Created File " + newfile)
			else:
				print("File " + path + str(chr(65 + i)) + ".cpp exits already!")

if __name__ == "__main__":
	main()




