class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int totalSize = n1 + n2;
        int midIndex1 = (totalSize - 1) / 2;
        int midIndex2 = totalSize / 2;
        int count = 0;
        int median1 = 0;
        int median2 = 0;

        while (i < n1 && j < n2) {
            int current;
            if (nums1[i] < nums2[j]) {
                current = nums1[i];
                i++;
            } else {
                current = nums2[j];
                j++;
            }
            if (count == midIndex1) median1 = current;
            if (count == midIndex2) median2 = current;
            count++;
        }

        while (i < n1) {
            if (count == midIndex1) median1 = nums1[i];
            if (count == midIndex2) median2 = nums1[i];
            count++;
            i++;
        }

        while (j < n2) {
            if (count == midIndex1) median1 = nums2[j];
            if (count == midIndex2) median2 = nums2[j];
            count++;
            j++;
        }

        if (totalSize % 2 == 1) {
            return median2;
        }

        return (median1 + median2) / 2.0;
    }
};