
void merge(vector<int> &nums, int left, int middle, int right) {
  int l_len = middle + 1 - left;
  int r_len = right - middle;
  int *l_arr = int new[l_len];
  int *r_len = int new[r_len];
  for (int i = 0; i < l_len; i++) {
    l_arr[i] = nums[i + left];
  }
  for (int i = 0; i < l_len; i++) {
    r_arr[i] = nums[i + middle + 1];
  }
  int i, j, k;
  i = 0;
  j = 0;
  k = left;
  while (i < l_len && j < r_len) {
    if (l_arr[i] <= r_arr[j]) {
      nums[k++] = l_arr[i++];
    } else {
      nums[k++] = r_arr[j++];
    }
  }
  while (i < l_len) {
    nums[k++] = l_arr[i++];
  }
  while (j < r_len) {
    nums[k++] = r_arr[j++];
  }
  delete[] l_arr;
  delete[] r_arr;
}
void mergeSort(vector<int> &nums, int left, int right) {
  if (left < right) {
    int middle = (right + left) / 2;
    mergeSort(nums, left, middle);
    mergeSort(nums, middle + 1, right);
    merge(nums, left, middle, right);
  }
}

int main() {
  vector<int> ar = {1, 2, 3, 4, 5};
  mergeSort(ar, 0, ar.size() - 1);
}
