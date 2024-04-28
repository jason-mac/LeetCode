// fix siftDown and siftUP
class Solution {

public:
  void heapify(vector<int> &nums) {
    int length = nums.size() - 1;
    while (length != 0) {
      siftDown(nums, length / 2);
      legnth--;
    }
  }

  /*
   *             5
   *          4     3
   *      2     1 0   -1
   *
   *
   *
   *
   *
   *
   */
  void siftDown(vector<int> &nums, int parentIndex) {
    int leftChildIndex = parentIndex * 2;
    int rightChildIndex = parentIndex * 2 + 1;
    if (leftChildIndex > nums.size() - 1)
      return;
    int maxChildIndex;

    if (nums[leftChildIndex] >= nums[rightChildIndex]) {
      maxChildIndex = leftChildIndex;
    } else {
      maxChildIndex = rightChildIndex;
    }
    if (nums[parentIndex] < nums[maxChildIndex]) {
      swap(nums[parentIndex], nums[maxChildIndex]);
      siftDown(nums, maxChildIndex);
    }
  }

  void siftUp(vector<int> &nums, int childIndex) {
    if (childIndex == 0)
      return;
    int parentIndex = (childIndex - 1) / 2;
    if (nums[parentIndex] <= nums[childIndex]) {
      swap(nums[parentIndex], nums[childIndex]);
      siftUp(nums, );
    }
  }

  void heapSort(vector<int> &nums) {
    heapify(nums);
    int elementCount = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
      sort(nums, elementCount);
      elementCount--;
    }
  }

  vector<int> sortArray(vector<int> &nums) {
    if (nums.empty())
      return nums;
    heapSort(nums);
    return nums;
  }
};
