import socket
import sys
import time

start = time.time()
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

if (len(sys.argv) != 3):
    print("provide a hostname and a port")
    quit()

hostname = sys.argv[1].lower()
port = int(sys.argv[2])
request = "GET / HTTP/1.1\r\nHost:%s\r\n\r\n" % hostname

client_socket.connect((hostname, port))
client_socket.send(request.encode())

response = client_socket.recv(1024)
print(response.decode("utf-8"))

end = time.time()
execution_time = (end - start) * 1000
print("\n\n\n\nexecution time: %sms" % execution_time)
