# prgrammes names
CLIENT_PRG = client
SERVER_PRG = server
# prgrammes bonus names
CLIENT_PRG_BNS = client_bns
SERVER_PRG_BNS = server_bns

NAME = minitlk
# manda client
CLIENT_SRC = client.c ft_comment_funcs.c
CLIENT_OBG = ${CLIENT_SRC:.c=.o}
# manda server
SERVER_SRC = server.c
SERVER_OBG = ${SERVER_SRC:.c=.o}  
# bonus server
SERVER_SRC_BNS = server_bonus.c
SERVER_OBG_BNS = ${SERVER_SRC_BNS:.c=.o}  
# bonus client
CLIENT_SRC_BNS = client_bonus.c ft_comment_funcs.c
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
bonus: ${FT_PRINTF} ${SERVER_PRG_BNS} ${CLIENT_PRG_BNS}

${SERVER_PRG_BNS}: ${SERVER_OBG_BNS}
	cc ${SERVER_OBG_BNS} ${FLAGS} ${FT_PRINTF} -o ${SERVER_PRG_BNS}

${CLIENT_PRG_BNS}: ${CLIENT_OBG_BNS}
	cc ${CLIENT_OBG_BNS} ${FLAGS} ${FT_PRINTF} -o ${CLIENT_PRG_BNS}

clean:
	make clean -C ft_printf/
	rm -f ${SERVER_OBG_BNS}
	rm -f ${CLIENT_OBG_BNS}
	rm -f ${CLIENT_OBG}
	rm -f ${SERVER_OBG}
fclean: clean
	make fclean -C ft_printf/
	rm -f ${CLIENT_PRG}
	rm -f ${SERVER_PRG}
	rm -f ${CLIENT_PRG_BNS}
	rm -f ${SERVER_PRG_BNS}

re: fclean all

.PHONY: all clean fclean re
