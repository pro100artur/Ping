#include <stdio.h>
int move_rocket(char key, int rl, int rr);
void map_redraw(int x_ball, int y_ball, int ball_direct_x, int ball_direct_y,
      int rocket_left, int rocket_right, int score_left, int score_riht);
int main() {
    int x_ball = 41;
    int y_ball = 14;
    int ball_direct_x = 1;
    int ball_direct_y = -1;
    int rocket_left = 13;
    int rocket_right = 13;
    char key;
    int score_left = 0;
    int score_right = 0;
    map_redraw(x_ball, y_ball, ball_direct_x, ball_direct_y, rocket_left, rocket_right, score_left, score_right);
    while (score_left < 21 && score_right < 21) {
      scanf("%c", &key);
      if (key == 'a' || key == 'z' || key == 'A' || key == 'Z' || key == 'k' || key == 'm' || key == 'K' ||key == 'M'|| key == ' ' ) {
          if (y_ball == 3) {
              ball_direct_y = ball_direct_y * (-1);
          } else if (x_ball == 4 && (y_ball == rocket_left || y_ball == rocket_left + 1 || y_ball == rocket_left + 2)) {
              ball_direct_x = ball_direct_x * (-1);
          } else if (y_ball == 24) {
              ball_direct_y = ball_direct_y * (-1);
          } else if (x_ball == 78 && (y_ball == rocket_right + 1 || y_ball == rocket_right + 2 || y_ball == rocket_right + 3)) {
          ball_direct_x = ball_direct_x * (-1);
          } else if (x_ball == 2) {
              score_right = score_right + 1;
              y_ball = 14;
              x_ball = 41;
              ball_direct_x = -1;
              ball_direct_y = -1;
              rocket_left = 13;
              rocket_right = 13;
          }
          else if (x_ball == 79) {
              score_left = score_left + 1;
              y_ball = 14;
              x_ball = 41;
              ball_direct_x = -1;
              ball_direct_y = -1;
              rocket_left = 13;
              rocket_right = 13;
          }
      if (key == 'a' ||key == 'A' || key == 'z' || key == 'Z') {
          rocket_left = rocket_left + move_rocket(key, rocket_left, rocket_right);
      }
      else if (key == 'k' ||key == 'K' || key == 'm' || key == 'M') {
          rocket_right = rocket_right + move_rocket(key, rocket_left, rocket_right);
      }
      
      x_ball = x_ball + ball_direct_x;
      y_ball = y_ball + ball_direct_y;
      map_redraw(x_ball, y_ball, ball_direct_x, ball_direct_y, rocket_left, rocket_right, score_left, score_right);
      }
        

          
          
        }
    }

      
void map_redraw(int x_ball, int y_ball, int ball_direct_x, int ball_direct_y,
                int rocket_left, int rocket_right, int score_left, int score_right) {
    printf("\e[1;[1H\e[1J");
    int i, j;
    char space = ' ';
    char ball = '@';
    //  int space_i = ' ';
    if (score_left < 10) {
    printf("%38c%d:%d\n", space, score_left, score_right);
    } else {
    printf("%37c%d:%d\n", space, score_left, score_right);
    }
    for (i = 1; i <= 27; i++) {
    for (j = 1; j <= 82; j++) {
        if (i == 1 || i == 27) {
        printf("—");
        } else if ((i == rocket_left || i == rocket_left + 1 || i == rocket_left + 2) && j == 3) {
        printf("|");
        } else if ((i == rocket_right || i == rocket_right + 1 || i == rocket_right + 2) && j == 80) {
        printf("|");
        } else if (j == x_ball + ball_direct_x && i == y_ball + ball_direct_y) {
        printf("%c", ball);
        } else if (j == 1 || j == 82) {
        printf("|");
        } else {
        printf("%c", space);
        }
    }
    printf("\n");
    }
}


int move_rocket(char k, int rl, int rr) {
  if (rl + 2 == 26 || rr + 2 == 26){
    if (k == 'a' || k == 'A' || k == 'k' || k == 'K') {
      return -1;
    } else if (k == 'z' || k == 'Z' || k == 'M' || k == 'm'){
      return 0;
    }
  } else if (rl == 2 || rr == 2) {
    if (k == 'a' || k == 'A' || k == 'k' || k == 'K') {
      return 0;
    } else if (k == 'z' || k == 'Z' || k == 'M' || k == 'm'){
      return 1;
    }
  } else {
    if (k == 'a' || k == 'A' || k == 'k' || k == 'K') {
      return -1;
    } else if (k == 'z' || k == 'Z' || k == 'M' || k == 'm'){
      return 1;
    }
  }
  return 0;
}

