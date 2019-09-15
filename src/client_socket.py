import socket
import sys

# AF_INET stands to Address Family Internet (IPv4), and SOCK_STREAM corresponds to TCP
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

if (len(sys.argv) != 3):
    print("Please provide a hostname and a port")
    quit()

hostname = sys.argv[1]
port = int(sys.argv[2])
request = "GET / HTTP/1.1\r\nHost:%s\r\n\r\n" % hostname

s.connect((hostname, port))
s.send(request.encode())

response = s.recv(1024)
print(response.decode("utf-8"))
