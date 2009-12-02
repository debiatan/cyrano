#!/usr/bin/env python

from pyrano import Pyrano

import time

my_board = Pyrano('/dev/ttyUSB0')

time.sleep(2)
print my_board.listOps()
my_board.close()
