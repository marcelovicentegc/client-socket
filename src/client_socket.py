import socket
import sys

# AF_INET corresponds to IPv4, and SOCK_STREAM corresponds to TCP
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# s.connect(("blablabla", 80))
# if (len(sys.argv) != 3):
#     print("Please provide a hostname and a port")
#     quit()


# s.connect((sys.argv[0], sys.argv[1]))
s.connect((socket.gethostname(), 4000))

# Buffer size
msg = s.recv(1024)
print(msg.decode("utf-8"))