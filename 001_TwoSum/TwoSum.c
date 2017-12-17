#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target) {
  int *ret_result = (int *)malloc(2 * sizeof(int));
  int i = 0, j = 0;
  for (i = 0; i < numsSize; i++) {
    for (j = i + 1; j < numsSize; j++) {
      if ((nums[i] + nums[j]) == target) {
        ret_result[0] = i;
        ret_result[1] = j;
        return ret_result;
      }
    }
  }

  return NULL;
}

int main(int argc, char const *argv[]) {
  int nums[4] = {2, 7, 11, 15};
  int *ret;
  char *p;
  ret = twoSum(nums, sizeof(nums), 9);
  printf("%d\n", ret[0]);
  printf("sizeof(char*)=%lu\n", sizeof(char *));  // 8
  printf("sizeof(char)=%lu\n", sizeof(char));     // 1
  printf("sizeof(int)=%lu\n", sizeof(int));       // 4
  printf("sizeof(p)=%lu\n", sizeof(p));           // 8
  printf("sizeof(nums)=%lu\n", sizeof(nums));     // 16
  printf("sizeof(double)=%lu\n", sizeof(double)); // 8
  printf("sizeof(long)=%lu\n", sizeof(long));     // 8
  return 0;
}
