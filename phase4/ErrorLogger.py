class ErrorLogger:
    def __init__(self):
        self.errors = []
    
    def recordError(self,error):
        if not isinstance(error, str):
            raise TypeError("Error message must be a string")
        self.errors.append(error)

    def displayError(self):
        print(self.errors)

def main():
    errorLogger = ErrorLogger()
    errorLogger.recordError("Error: File not found")
    errorLogger.displayError()

if __name__ == "__main__":
    main()