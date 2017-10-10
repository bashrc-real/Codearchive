import time
import eventlet

eventlet.monkey_patch()
def ExecuteMethodUnderTimeout(method, timeoutInSeconds, exception = RuntimeError("timeout")):
    with eventlet.timeout.Timeout(timeoutInSeconds, exception):
        method()

