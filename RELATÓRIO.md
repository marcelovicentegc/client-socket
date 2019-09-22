# RELATÓRIO: Cliente HTTP e Wireshark

## 1.1 Desenvolvimento do cliente HTTP

[Código fonte em C](./src/client_socket.c)\
[Código fonte em Golang](./src/goClientSocket/clientSocket.go)\
[Código fonte em Python](./src/client_socket.py)\
[Código fonte em Lua](./src/client_socket.lua)

## 1.2 Teste do cliente HTTP

> [Screenshots do output do console](./SCREENSHOTS.md)

## 2.1 Captura dos pacotes com Wireshark

## 2.2 Visualização da captura do Wireshark

1. O pacote que indica o estabelecimento de uma conexão client-servidor é o que contém flags TCP `SYN`, em função do `three-way handshake`. Logo, aproveitei o filtro do Wireshark para identificar o passo em que o servidor retorna o `ACK` 1, confirmando o recebimento do primeiro pacote pelo cliente e, literalmente um passo ao início da futura transferência de dados, utilisando a expressão `tcp.flags.syn==1 && tcp.flags.ack==1`. 

> [Screenshots dos pacotes](./SYN.md)

2. O pacote que indica o fim de uma conexão contém a flag TCP `FIN`, logo, filtrei este pacote utilisando a expressão `tcp.flags.fin==1 && tcp.flags.ack==1`:

> [Screenshots dos pacotes](./FIN.md)

3. A função, tanto do registro de tipo A quanto do registro de tipo AAAA, é de converter um IP para um domínio. Todas as queries realizadas apontaram para um host através do IPv4 (por exemplo: `216.58.222.99` (www.google.com.br)) - um endereço composto por 32 bits, diferente dos endereços IPv6 (por exemplo: `2800:3f0:4004:805::2003` (www.google.com.br)), compostos por 128 bits -, ou seja, realizaram uma query DNS de tipo A. A principal diferença entre as solicitações de tipo A e as de tipo AAAA referem-se ao `checksum`, incluido no header do pacote de tipo A e ausentes no header do pacote de tipo AAAA:

4. | `www.globo.com` | `www.google.com.br` | `www.msn.com`    |
   | --------------- | ------------------- | ---------------- |
   | `186.192.81.5`  | `216.58.222.99`     | `204.79.197.203` |

5. | `www.globo.com`         | `www.google.com.br` | `www.msn.com` |
   | ----------------------- | ------------------- | ------------- |
   | `301 Moved Permanently` | `200 Ok`            | `302 Found`   |
