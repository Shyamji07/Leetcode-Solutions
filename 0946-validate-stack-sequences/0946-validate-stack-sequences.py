class Solution(object):
    def validateStackSequences(self, pushed, popped):
        j = 0
        st = []
        for x in pushed:
            st.append(x)
            while st and j < len(popped) and st[-1] == popped[j]:
                st.pop()
                j += 1
        return j == len(popped)