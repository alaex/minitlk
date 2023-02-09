# prgrammes names
CLIENT_PRG = client
SERVER_PRG = server
NAME = minitlk
# manda client
CLIENT_SRC = client.c
CLIENT_OBG = ${CLIENT_SRC:.c=.o}
# manda server
SERVER_SRC = server.c
SERVER_OBG = ${SERVER_SRC:.c=.o}  
# bonus server
SERVER_SRC_BNS = server_bonus.c
SERVER_OBG_BNS = ${SERVER_SRC_BNS:.c=.o}  
# bonus client
CLIENT_SRC_BNS = client_bonus.c
CLIENT_OBG_BNS = ${CLIENT_SRC_BNS:.c=.o}
# requarmentation
FT_PRINTF = ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror

all: ${FT_PRINTF} ${NAME}

%.o: %.c minitlk.h
	cc ${FLAGS} -c $< -o $@
# manda
${NAME}: server client

server: ${SERVER_OBG}
	cc ${SERVER_OBG} ${FLAGS} ${FT_PRINTF} -o ${SERVER_PRG}
client: ${CLIENT_OBG}
	cc ${CLIENT_OBG} ${FLAGS} ${FT_PRINTF} -o ${CLIENT_PRG}

${FT_PRINTF}:
	cd ft_printf && make
# bonus
bonus: ${FT_PRINTF} $(SERVER_OBG_BNS) $(CLIENT_OBG_BNS)

server_bns: ${SERVER_OBG_BNS}
	cc ${SERVER_OBG_BNS} ${FLAGS} ${FT_PRINTF} -o ${SERVER_PRG}

client_bns: ${CLIENT_OBG_BNS}
	cc ${CLIENT_OBG_BNS} ${FLAGS} ${FT_PRINTF} -o ${CLIENT_PRG}

clean:
	make clean -C ft_printf/
	rm *.o
fclean: clean
	make fclean -C ft_printf/
	rm ${CLIENT_PRG}
	rm ${SERVER_PRG}

re: fclean all

.PHONY: all clean fclean re
