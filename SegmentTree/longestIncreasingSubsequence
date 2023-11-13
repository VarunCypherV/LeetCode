class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * 4 * self.n

    # query (qleft, qright) to find maximum elements in range [qleft...qright]
    def query(self, left, right, index, qleft, qright):
        if qright < left or qleft > right:
            return 0

        if qleft <= left and right <= qright:
            return self.tree[index]

        mid = (left + right) // 2
        resLeft = self.query(left, mid, 2 * index + 1, qleft, qright)
        resRight = self.query(mid + 1, right, 2 * index + 2, qleft, qright)
        return max(resLeft, resRight)

    # update an element at `pos` to `val`
    def update(self, left, right, index, pos, val):
        if left == right:
            self.tree[index] = val
            return

        mid = (left + right) // 2
        if pos <= mid:
            self.update(left, mid, 2 * index + 1, pos, val)
        else:
            self.update(mid + 1, right, 2 * index + 2, pos, val)
        self.tree[index] = max(self.tree[2 * index + 1], self.tree[2 * index + 2])


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        def compress(arr):  # Example: [1, 9999, 20, 10, 20] -> Expected: [0, 3, 2, 1, 2]
            sortedArr = sorted(arr)
            ans = []
            for x in arr:
                ans.append(bisect_left(sortedArr, x))
            return ans

        nums = compress(nums)
        n = len(nums)
        segmentTree = SegmentTree(n)
        for x in nums:
            subLongest = segmentTree.query(0, n - 1, 0, 0, x - 1)
            segmentTree.update(0, n - 1, 0, x, subLongest + 1)
        return segmentTree.query(0, n - 1, 0, 0, n - 1)