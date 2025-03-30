#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define NUM_SCHOOLS 5

// 定义学校结构体
typedef struct {
  char name[MAX_NAME_LEN]; // 学校名称
  int male_score;          // 男生总分
  int female_score;        // 女生总分
} School;

void init_schools(School schools[]) {
  const char *names[] = {"A", "B", "C", "D", "E"};
  for (int i = 0; i < NUM_SCHOOLS; i++) {
    strcpy(schools[i].name, names[i]);
    schools[i].male_score = 0;
    schools[i].female_score = 0;
  }
}

// 查找学校索引
int find_school_index(const char *name, School schools[]) {
  for (int i = 0; i < NUM_SCHOOLS; i++) {
    if (strcmp(name, schools[i].name) == 0) {
      return i;
    }
  }
  return -1; // 未找到
}

int main() {
  School schools[NUM_SCHOOLS];
  init_schools(schools); // 初始化学校数组

  char event[MAX_NAME_LEN], gender, school_name[MAX_NAME_LEN];
  int score;

  // 读取输入并处理
  while (scanf("%s %c %s %d", event, &gender, school_name, &score) != EOF) {
    int index = find_school_index(school_name, schools);
    if (index == -1)
      continue; // 忽略无效学校

    if (gender == 'M') {
      schools[index].male_score += score;
    } else if (gender == 'F') {
      schools[index].female_score += score;
    }
  }

  // 输出结果
  for (int i = 0; i < NUM_SCHOOLS; i++) {
    int male_score = schools[i].male_score;
    int female_score = schools[i].female_score;
    int total_score = male_score + female_score;

    // 输出男生总分
    if (male_score > 0) {
      printf("%s M %d\n", schools[i].name, male_score);
    }

    // 输出女生总分
    if (female_score > 0) {
      printf("%s F %d\n", schools[i].name, female_score);
    }

    // 输出团体总分
    if (total_score > 0) {
      printf("%s %d\n", schools[i].name, total_score);
    }
  }

  return 0;

}
