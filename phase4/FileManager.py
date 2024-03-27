class FileManager:
    filePath=""
    
    def __init__(self,filePath):
        self.filePath=filePath
        
    def readFile(self,fileName):
        ##get file name most likely from file path 
        
        with open(fileName, "r") as f:
            return f.read()
        
    def logError(self, fileName, error):
        with open(fileName, "w") as f:
            f.write(error)

    
    def updateFile(self,fileName,transaction):
        f=open(fileName,"a")
        f.write(transaction)
        f.close

def main():
    fileManager = FileManager("transactions.txt")
    fileManager.readFile("transactions.txt")
    fileManager.logError("errorLog.txt","Error: File not found")
    fileManager.updateFile("transactions.txt","John Doe has deposited $1001\n")

if __name__ == "__main__":
    main()
