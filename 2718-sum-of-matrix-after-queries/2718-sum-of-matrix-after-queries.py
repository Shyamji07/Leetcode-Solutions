class Solution:
    def matrixSumQueries(self, n: int, queries: List[List[int]]) -> int:

        # make dictionary with default value of [1,1] where first
        # value represents whether type 0 is processed or not.
        # Similarly, second value represents whether type 1 is
        # processed or not
        d = defaultdict(lambda: [1,1])

        # stores the summation of vlaues of matrix entries
        ans = 0

        # cr, cc denotes number of rows / columns processed
        cr, cc = 0, 0

        # start query from reversed fashion as we know the fact we can overwrite the
        # values
        for x, y, z in reversed(queries):

            # For index = y and type = x, process the matrix and
            # later, make the value to 0.
            # (Remember, we move in reversed manner)
            # Eg. for a particular query with index y and type 0,
            # we made d[y] = [0,1], so that we've liabilty to process
            # index y with type 1 as it is set to 1
            if d[y][x]:
                # x = 0 means type 0, so increment row's count
                if x == 0:
                    cr += 1
                # x = 1 means type 1, so increment col's count
                else:
                    cc += 1

                # while processing yth row, we've to remove those columns which are
                # already processed
                if x == 0:
                    remaining = n - cc
                # while processing yth col, we've to remove those rows which are
                # already processed
                else:
                    remaining = n - cr

                # multiply with value to get the desired result and add to variable ans    
                ans += remaining * z

                # since, we process the yth row / col depend upon type i.e. x, we can
                # now mark to 0 (Remember, we move in reversed manner)
                d[y][x] = 0

        return ans