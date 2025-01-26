# File: ai/dpdlAISnakeGame_gen.h
#
# Example: The code below is the output of the automatically AI generated code when running the Dpdl code './ai/dpdlAISnakeGame.h'
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("testing the Dpdl language plugin 'DpdlAINerd' to automatically generate and execute code...")

dpdl_stack_push("dpdl:compile")

>>c
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20
#define INITIAL_LENGTH 3

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position body[WIDTH * HEIGHT];
    int length;
    int direction;
} Snake;

typedef struct {
    int x, y;
} Food;

Snake snake;
Food food;
int score = 0;
bool game_over = false;

void setup() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();

    // Initialize colors
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // Snake color
    init_pair(2, COLOR_RED, COLOR_BLACK);   // Food color
    init_pair(3, COLOR_WHITE, COLOR_BLACK); // Border color

    // Initialize snake
    snake.length = INITIAL_LENGTH;
    snake.direction = KEY_RIGHT;
    for (int i = 0; i < snake.length; i++) {
        snake.body[i].x = WIDTH / 2 - i;
        snake.body[i].y = HEIGHT / 2;
    }

    // Initialize food
    srand(time(NULL));
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

void draw() {
    clear();

    // Draw border
    attron(COLOR_PAIR(3));
    for (int i = 0; i < WIDTH + 2; i++) {
        mvprintw(0, i, "#");
        mvprintw(HEIGHT + 1, i, "#");
    }
    for (int i = 0; i < HEIGHT + 2; i++) {
        mvprintw(i, 0, "#");
        mvprintw(i, WIDTH + 1, "#");
    }
    attroff(COLOR_PAIR(3));

    // Draw snake
    attron(COLOR_PAIR(1));
    for (int i = 0; i < snake.length; i++) {
        mvprintw(snake.body[i].y, snake.body[i].x, "O");
    }
    attroff(COLOR_PAIR(1));

    // Draw food
    attron(COLOR_PAIR(2));
    mvprintw(food.y, food.x, "@");
    attroff(COLOR_PAIR(2));

    // Draw score
    mvprintw(HEIGHT + 2, 0, "Score: %d", score);

    refresh();
}

void input() {
    int ch = getch();
    switch (ch) {
        case KEY_UP:
            if (snake.direction != KEY_DOWN)
                snake.direction = KEY_UP;
            break;
        case KEY_DOWN:
            if (snake.direction != KEY_UP)
                snake.direction = KEY_DOWN;
            break;
        case KEY_LEFT:
            if (snake.direction != KEY_RIGHT)
                snake.direction = KEY_LEFT;
            break;
        case KEY_RIGHT:
            if (snake.direction != KEY_LEFT)
                snake.direction = KEY_RIGHT;
            break;
        case 'q':
            game_over = true;
            break;
    }
}

void logic() {
    // Move snake
    Position prev = snake.body[0];
    Position next = prev;

    switch (snake.direction) {
        case KEY_UP:
            next.y--;
            break;
        case KEY_DOWN:
            next.y++;
            break;
        case KEY_LEFT:
            next.x--;
            break;
        case KEY_RIGHT:
            next.x++;
            break;
    }

    // Check for collision with walls
    if (next.x <= 0 || next.x >= WIDTH || next.y <= 0 || next.y >= HEIGHT) {
        game_over = true;
        return;
    }

    // Check for collision with itself
    for (int i = 1; i < snake.length; i++) {
        if (next.x == snake.body[i].x && next.y == snake.body[i].y) {
            game_over = true;
            return;
        }
    }

    // Check for collision with food
    if (next.x == food.x && next.y == food.y) {
        snake.length++;
        score += 10;
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;
    } else {
        // Shift the body
        for (int i = snake.length - 1; i > 0; i--) {
            snake.body[i] = snake.body[i - 1];
        }
    }

    snake.body[0] = next;
}

int dpdl_main(int argc, char **argv) {
    setup();

    while (!game_over) {
        draw();
        input();
        logic();
        usleep(100000); // Sleep for 100ms
    }

    endwin();
    printf("Game Over! Your score: %d\n", score);
    return 0;
}
<<
int exit_code = dpdl_exit_code()

raise(exit_code, "Error in generating code from natural language description")

println("exit code: " + exit_code)

println("finished")
