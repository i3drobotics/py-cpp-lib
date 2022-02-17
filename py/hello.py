
class hello:
    def __init__(self):
        self.msg = "hello world"

    def getMsg(self) -> str:
        return self.msg

    def setMsg(self, msg: str) -> bool:
        self.msg = msg
        return True