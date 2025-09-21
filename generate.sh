#!/bin/bash

# Format

c_formatter_42 $(find . -type f \( -name "*.c" -o -name "*.h" \))

# Comprobar si se pasó un argumento para el nombre del programa
if [ -n "$1" ]; then
    NAME="$1"
else
    NAME="programa"
fi

# Configuración del compilador y flags
CC="cc"
CFLAGS="-Wall -Wextra -Werror"
INCLUDES="-I./includes -I./includes_copy"

# Directorios
SRC_DIR="./src"
OBJ_DIR="obj"

# Generar la lista de fuentes
SRCS_LIST=($(ls "$SRC_DIR"/*.c))  # Array con todos los archivos .c

# Construir la variable SRCS
SRCS="SRCS= "
for i in "${!SRCS_LIST[@]}"; do
    file="${SRCS_LIST[$i]}"
    SRCS+="$file "
done
SRCS="${SRCS% }"  # Quita el espacio final

# Generar Makefile
cat > Makefile <<EOL
CC      = $CC
CFLAGS  = $CFLAGS
INCLUDES= $INCLUDES

OBJ_DIR = $OBJ_DIR
NAME    = $NAME

$SRCS

OBJS    = \$(SRCS:./src/%.c=\$(OBJ_DIR)/src/%.o)

all: \$(NAME)

\$(NAME): \$(OBJS)
	\$(CC) \$(CFLAGS) \$(INCLUDES) -o \$@ \$^

\$(OBJ_DIR)/src/%.o: ./src/%.c | \$(OBJ_DIR)/src
	\$(CC) \$(CFLAGS) \$(INCLUDES) -c \$< -o \$@

\$(OBJ_DIR)/src:
	mkdir -p \$@

clean:
	rm -rf \$(OBJ_DIR)

fclean: clean
	rm -f \$(NAME)

re: fclean all

.PHONY: all clean fclean re
EOL

echo "Makefile generado correctamente con nombre de programa: $NAME"
