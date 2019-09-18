
if (#arg ~= 2) then
    print("please provide a hostname and a socket") 
    os.exit()  
end

local host, port = arg[1], arg[2]
local address = arg[1] .. ":" .. arg[2]
local socket = require("socket")
local tcp = assert(socket.tcp())

tcp:connect(host, port);
tcp:send("GET / HTTP/1.1\r\nHost:" ..address.. "\r\n\r\n");

while true do
    local s, status, partial = tcp:receive()
    print(s or partial)
    if status == "closed" then break end
end

tcp:close()
os.exit()