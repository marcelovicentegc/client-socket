# ⚽️ client-socket

## Directions

### Python

1. Make sure you have `python 3.6.5` onwards installed
2. Run `python3 src/client_socket.py <hostname> <port>` (i.g. `python src/client_socket.py www.google.com 80`)

### C

1. Compile it: `gcc src/client_socket.c -o <file_name>` (i.g. `gcc src/client_socket.c -o client_socket`)
2. Run it: `./<file_name> <hostname> <port>` (i.g. `./client_socket www.google.com 80`)

### Go️

1. Make sure you have `go 1.12.5` onwards installed
1. Run `go run src/goClientSocket/clientSocket.go --hostname <hostname> --port <port>` (i.g. `go run src/goClientSocket/clientSocket.go --hostname www.google.com --port 80`)
