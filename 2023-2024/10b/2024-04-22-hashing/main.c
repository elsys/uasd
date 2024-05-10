#include <stdio.h>
#include <string.h>
#include <math.h>

signed int hash_fn_1(char* str) {
  signed int code = 0;

  for(int i = 0; i < strlen(str); i++)
    code += str[i];

  return code;
}

signed int hash_fn_2(char* str) {
  signed int code = 0;

  for(int i = 0; i < strlen(str); i++)
    code += str[i] * pow(10, 6);

  return code;
}

// djb2
signed int hash_fn_3(char* str) {
  signed int code = 5381;

  for(int i = 0; i < strlen(str); i++)
    // code = (code << 5) + code + str[i];
    code = (code << 5) + (code * 33) + str[i];

  return code;
}

signed int hash_fn_4(void* str, size_t size) {
  signed int code = 5381;

  for(int i = 0; i < size; i++)
    // code = (code << 5) + code + str[i];
    code = (code << 5) + (code * 33) + ((unsigned char*)str)[i];

  return code;
}


struct point_t {
  int x;
  int y;
  int z;
};

struct student_t {
  char* first_name;
  char* last_name;
  unsigned short age;
};

int main() {
  puts("\nSimple cases:");
  printf("%d\n", hash_fn_3("hello"));
  printf("%d\n", hash_fn_3("llohe"));
  printf("%d\n", hash_fn_3("aa"));
  printf("%d\n", hash_fn_3("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
  printf("%d\n", hash_fn_3("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"));
  puts("\nRandom strings:");
  printf("%d\n", hash_fn_3("HGVVWhAIKYTOs9T"));
  printf("%d\n", hash_fn_3("74UocdtH3MQM9Vb"));
  printf("%d\n", hash_fn_3("yLLTHFGTIBWuCEY"));
  printf("%d\n", hash_fn_3("BvFbWDr7dQDhkQv"));
  printf("%d\n", hash_fn_3("7nAFGi8tANMtYpb"));

  puts("\nhash_fn_4:");
  printf("%d\n", hash_fn_4("HGVVWhAIKYTOs9T", strlen("HGVVWhAIKYTOs9T")));
  printf("%d\n", hash_fn_4("74UocdtH3MQM9Vb", strlen("74UocdtH3MQM9Vb")));
  printf("%d\n", hash_fn_4("yLLTHFGTIBWuCEY", strlen("yLLTHFGTIBWuCEY")));
  printf("%d\n", hash_fn_4("BvFbWDr7dQDhkQv", strlen("BvFbWDr7dQDhkQv")));
  printf("%d\n", hash_fn_4("7nAFGi8tANMtYpb", strlen("7nAFGi8tANMtYpb")));

  struct point_t p1 = {5, 10, 15};
  struct point_t p2 = {15, 10, 5};
  struct point_t p3 = {5, 10, 15};

  puts("\nstruct point_t:");
  printf("%d\n", hash_fn_4(&p1, sizeof(struct point_t)));
  printf("%d\n", hash_fn_4(&p2, sizeof(struct point_t)));
  printf("%d\n", hash_fn_4(&p3, sizeof(struct point_t)));

  struct student_t s1 = {"ivan", "ivanov", 15};
  struct student_t s2 = {"ivanov", "ivan", 15};
  struct student_t s3 = {"ivan", "ivanov", 15};

  puts("\nstruct student_t:");
  printf("%d\n", hash_fn_4(&s1, sizeof(struct student_t)));
  printf("%d\n", hash_fn_4(&s2, sizeof(struct student_t)));
  printf("%d\n", hash_fn_4(&s3, sizeof(struct student_t)));

  printf("%d\n", hash_fn_4(hash_fn_4, 5));

  return 0;
}