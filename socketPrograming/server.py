
from socket import *
serverName='DESKTOP-4AC610M'
serverPort = 12001
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
while 1:
 print ("The server is ready to receive")
 connectionSocket, addr = serverSocket.accept()
 sentence = connectionSocket.recv(1024).decode()
 
 file=open(sentence,"r")
 l=file.read(1024)
 
 connectionSocket.send(l.encode())
 print ('\nSent contents of ',sentence)
 file.close()
 connectionSocket.close()
