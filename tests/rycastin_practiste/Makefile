CC = gcc -g
CFLAGS = -O2 -std=c11
LDFLAGS = -lm

# MiniLibX (Linux) paths/libs
MLX_INC = /usr/include/minilibx-linux
MLX_LIBS = -L$(MLX_INC) -lmlx -lXext -lX11 -lm

SRC = raycast.c
BIN = raycast

MLX_SRC = mlx_raycast.c
MLX_BIN = mlx_raycast
TEST_SRC = test.c
TEST_BIN = test_mlx

MLX_test = test.c

.PHONY: all clean run mlx run-mlx

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BIN)

mlx: $(MLX_BIN)

test: $(MLX_test)
	$(CC) $(CFLAGS) -I$(MLX_INC) $(MLX_test) $(MLX_LIBS) -o test_mlx

$(MLX_BIN): $(MLX_SRC)
	$(CC) $(CFLAGS) -I$(MLX_INC) $(MLX_SRC) $(MLX_LIBS) -o $(MLX_BIN)

run: $(BIN)
	./$(BIN)

run-mlx: $(MLX_BIN)
	./$(MLX_BIN)

$(TEST_BIN): $(TEST_SRC)
	$(CC) $(CFLAGS) -I$(MLX_INC) $(TEST_SRC) $(MLX_LIBS) -o $(TEST_BIN)

.PHONY: test
test: $(TEST_BIN)
# 	./$(TEST_BIN)

clean:
	rm -f $(BIN) $(MLX_BIN) $(TEST_BIN)
