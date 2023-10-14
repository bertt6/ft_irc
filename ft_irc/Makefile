CLIENT_FILE = client.cpp
SERVER_FILE = server.cpp
CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
CLIENT_OBJ = $(CLIENT_FILE:.cpp=.o)
SERVER_OBJ = $(SERVER_FILE:.cpp=.o)
RM = rm -rf

CLIENT_NAME = client
SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_OBJ)
	$(CC) $(CPPFLAGS) $(CLIENT_OBJ) -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJ)
	$(CC) $(CPPFLAGS) $(SERVER_OBJ) -o $(SERVER_NAME)
clean:
	$(RM) -f *.o
fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)
re: fclean all

.PHONY: all clean fclean re