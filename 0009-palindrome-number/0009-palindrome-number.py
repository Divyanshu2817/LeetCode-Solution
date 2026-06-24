class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        t=x
        s=0
        while(t>0):
            re=t%10
            s=s*10+re
            t=t//10
        if (x==s):
            return True
        else:
            return False

        