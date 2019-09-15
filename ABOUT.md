# About 📘

## The steps involved in establishing a socket on the client side are as follows:

1. Create a socket with the `socket()` system call

2. Connect the socket to the address of the server using the `connect()` system call

3. Send and receive data. There are a number of ways to do this, but the simplest is to use the `read()` and `write()` system calls.

## Address domain and socket types

When a socket is created, the program has to specify the **address domain** and the **socket type**. Two processes can communicate with each other only if their sockets are of the same type and in the same domain. There are two widely used address domains, the `unix domain`, in which two processes which share a common file system communicate, and the `Internet domain`, in which two processes running on any two hosts on the Internet communicate. Each of these has its own address format.

The address of a socket in the Unix domain is a character string which is basically an entry in the file system.

The address of a socket in the Internet domain consists of the Internet address of the host machine (every computer on the Internet has a unique 32 bit address, often referred to as its IP address). In addition, each socket needs a port number on that host. Port numbers are 16 bit unsigned integers. The lower numbers are reserved in Unix for standard services. For example, the port number for the FTP server is 21. It is important that standard services be at the same port on all computers so that clients will know their addresses. However, port numbers above 2000 are generally available.

There are two widely used socket types, `stream sockets`, and `datagram sockets`. Stream sockets treat communications as a continuous stream of characters, while datagram sockets have to read entire messages at once. Each uses its own communciations protocol. Stream sockets use TCP (Transmission Control Protocol), which is a reliable, stream oriented protocol, and datagram sockets use UDP (Unix Datagram Protocol), which is unreliable and message oriented.

#### Source
[Sockets tutorial](https://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html)
