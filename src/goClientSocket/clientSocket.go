package main

import (
	"bufio"
	"flag"
	"fmt"
	"net"
	"os"
	"strings"
	"time"
)

type Client struct {
	socket net.Conn
	data   chan []byte
}

var start time.Time

func init() {
	start = time.Now()
}

func (client *Client) receive() {
	for {
		response := make([]byte, 1024)
		length, err := client.socket.Read(response)

		if err != nil {
			client.socket.Close()
			break
		}

		if length > 0 {
			fmt.Println(string(response))
			fmt.Printf("\n\n\n\n execution time: %v\n", time.Since(start))
			os.Exit(0)
		}
	}
}

func send(hostname, port string) {
	connection, error := net.Dial("tcp", net.JoinHostPort(hostname, port))

	if error != nil {
		fmt.Println(error)
	}

	var header = fmt.Sprintf("GET / HTTP/1.1\r\nHost:%s\r\n\r\n", hostname)
	fmt.Fprintf(connection, header)
	client := &Client{socket: connection}

	go client.receive()

	for {
		reader := bufio.NewReader(os.Stdin)
		response, _ := reader.ReadString('\n')
		connection.Write([]byte(strings.TrimRight(response, "\n")))
	}
}

func main() {
	hostname := flag.String("hostname", "", "address which the socket will send a request")
	port := flag.String("port", "", "port which the socket should send a request (usually 80 or 443)")
	flag.Parse()

	if len(*hostname) == 0 {
		fmt.Println("provide a host")
		os.Exit(0)
	}

	if len(*port) == 0 {
		fmt.Println("provide a port")
		os.Exit(0)
	}

	send(*hostname, *port)
}
