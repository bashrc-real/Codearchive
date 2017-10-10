from __future__ import  print_function
import RunWithTimeout
import time

try:
    RunWithTimeout.ExecuteMethodUnderTimeout( lambda : time.sleep(10), 2)
    print("Failed timeout didn't happen")
except RuntimeError:
    print("timeout")

try:
    RunWithTimeout.ExecuteMethodUnderTimeout(lambda : time.sleep(1), 10)
    print("Success1")
except RuntimeError:
    print("Failed Timeout2 happened")