all: 
	echo "clean, run_server, run_client, build_server, build_client"
build_server:
	gcc tcp_server.c -o a.server
run_server:
	./a.server
build_client:
	gcc tcp_client.c -o a.client
run_client:
	./a.client
clean:
	rm a.client a.server
build_server_wind:
	gcc tcp_server_wind.cpp -o a.tcp_server_wind.exe -lws2_32
build_client_wind:
	gcc tcp_client_wind.cpp -o a.tcp_client_wind.exe -lws2_32


