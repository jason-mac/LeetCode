class Solution {
public:
  void merge(vector<int> &nums, int left, int middle, int right) {
    int leftLength = middle + 1 - left;
    int rightLength = right - middle;
    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];
    for (int i = 0; i < leftLength; i++) {
      leftArr[i] = nums[left + i];
    }
    for (int j = 0; j < rightLength; j++) {
      rightArr[j] = nums[middle + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = left;
    while (i < leftLength && j < rightLength) {
      if (leftArr[i] <= rightArr[j]) {
        nums[k++] = leftArr[i++];
      } else {
        nums[k++] = rightArr[j++];
      }
    }
    while (i < leftLength) {
      nums[k++] = leftArr[i++];
    }
    while (j < rightLength) {
      nums[k++] = rightArr[j++];
    }
    delete[] leftArr;
    delete[] rightArr;
  }
  void mergeSort(vector<int> &nums, int left, int right) {
    if (left < right) {
      int middle = (left + right) / 2;
      mergeSort(nums, left, middle);
      mergeSort(nums, middle + 1, right);
      merge(nums, left, middle, right);
    }
  }
  vector<int> sortArray(vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }
};
