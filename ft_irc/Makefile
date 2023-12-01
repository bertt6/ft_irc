NAME = ircserv
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g 
OBJECTS = $(FILE:.cpp=.o)
FILE = server.cpp \
	main.cpp \
	user.cpp \
	commands.cpp channel.cpp \
	./commands/nick.cpp \
	./commands/pass.cpp \
	./commands/user.cpp \
	./commands/Quit.cpp \
	./commands/ping.cpp \
	./commands/join.cpp \
	./commands/kick.cpp \
	./commands/part.cpp \
	./commands/privmsg.cpp \
	./commands/topic.cpp \
	./commands/mode.cpp \
	./commands/cap.cpp \
	./commands/notice.cpp 
RM = rm -rf

all: $(NAME)

$(NAME): $(FILE)
	$(CC) $(CPPFLAGS) -o $(NAME) $(FILE)
.c.o:
	${CC} ${CPPFLAGS} -C $< -o ${OBJECTS}
clean:
	$(RM) -f *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re