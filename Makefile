CLIENT_PRG = client
CLIENT_SRC = client.c
CLIENT_OBG = ${CLIENT_SRC:.c=.o}

SERVER_PRG = server
SERVER_SRC = server.c
SERVER_OBG = ${SERVER_SRC:.c=.o}  

# requarmentation
FT_PRINTF = ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror

# %.o: %.c
# 	cc ${FLAGS} -c $< -o $@

all: me

%.o: %.c server.h
	cc ${FLAGS} -c $< -o $@

me: ${FT_PRINTF} ${SERVER_OBG} ${CLIENT_OBG}
	cc ${SERVER_OBG} ${FLAGS} ${FT_PRINTF} -o ${SERVER_PRG}
	cc ${CLIENT_OBG} ${FLAGS} ${FT_PRINTF} -o ${CLIENT_PRG}

${FT_PRINTF}:
	cd ft_printf && make


clean:
	make clean -C ft_printf/
	rm ${SERVER_OBG}
	rm ${CLIENT_OBG}
fclean: clean
	make fclean -C ft_printf/
	rm ${CLIENT_PRG}
	rm ${SERVER_PRG}